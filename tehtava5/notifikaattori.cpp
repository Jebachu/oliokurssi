#include "Notifikaattori.h"

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {}

void Notifikaattori::lisaa(Seuraaja* uusiSeuraaja) {
    uusiSeuraaja->next = seuraajat;
    seuraajat = uusiSeuraaja;
}

void Notifikaattori::poista(Seuraaja* poistettava) {
    if (!seuraajat) return;

    if (seuraajat == poistettava) {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja* nykyinen = seuraajat;
    while (nykyinen->next && nykyinen->next != poistettava) {
        nykyinen = nykyinen->next;
    }

    if (nykyinen->next) {
        nykyinen->next = poistettava->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        std::cout << nykyinen->getName() << std::endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(std::string viesti) {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
