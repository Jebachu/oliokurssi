#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
#include <string>

class Seuraaja {
private:
    std::string nimi;

public:
    Seuraaja* next = nullptr;

    Seuraaja(std::string nimi);
    std::string getName();
    void paivitys(std::string viesti);
};

#endif // SEURAAJA_H
