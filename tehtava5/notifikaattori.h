#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"

class Notifikaattori {
private:
    Seuraaja* seuraajat = nullptr;

public:
    Notifikaattori();
    void lisaa(Seuraaja* uusiSeuraaja);
    void poista(Seuraaja* poistettava);
    void tulosta();
    void postita(std::string viesti);
};

#endif // NOTIFIKAATTORI_H
