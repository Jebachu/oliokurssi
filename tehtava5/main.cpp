#include <iostream>
#include "Notifikaattori.h"

using namespace std;

int main() {
    Notifikaattori notifikaattori;

    // Luodaan seuraajat
    Seuraaja* s1 = new Seuraaja("Jamppa");
    Seuraaja* s2 = new Seuraaja("Maarit");
    Seuraaja* s3 = new Seuraaja("Pasi");

    // Lisätään seuraajat notifikaattoriin
    notifikaattori.lisaa(s1);
    notifikaattori.lisaa(s2);
    notifikaattori.lisaa(s3);

    // Tulostetaan seuraajat
    std::cout << "Seuraajat:" << std::endl;
    notifikaattori.tulosta();

    // Lähetetään viesti kaikille seuraajille
    std::cout << "\nLaitetaan viesti..." << std::endl;
    notifikaattori.postita("Tama on viesti!");

    // Poistetaan yksi seuraaja ja tulostetaan lista uudelleen
    notifikaattori.poista(s2);
    std::cout << "\nSeuraajat Maaritin poiston jalkeen:" << std::endl;
    notifikaattori.tulosta();

    // Vapautetaan muisti
    delete s1;
    delete s2;
    delete s3;

    return 0;
}
