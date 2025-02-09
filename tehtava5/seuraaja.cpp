#include "Seuraaja.h"

Seuraaja::Seuraaja(std::string nimi) : nimi(nimi), next(nullptr) {}

std::string Seuraaja::getName() {
    return nimi;
}

void Seuraaja::paivitys(std::string viesti) {
    std::cout << nimi << " sai viestin: " << viesti << std::endl;
}
