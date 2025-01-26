#include "ItalianChef.h"
#include <iostream>

ItalianChef::ItalianChef(const std::string& name) : Chef(name), flour(0), water(0) {
    std::cout << "ItalianChef " << getName() << " konstruktori." << std::endl;
}

ItalianChef::~ItalianChef() {
    std::cout << "ItalianChef " << getName() << " destruktori." << std::endl;
}

bool ItalianChef::askSecret(const std::string& pass, int flourAmount, int waterAmount) {
    if (pass == password) {
        flour = flourAmount;
        water = waterAmount;
        int pizzaResult = makePizza();
        std::cout << "Pizza made: " << pizzaResult << " pizzas." << std::endl;
        return true;
    } else {
        std::cout << "Wrong password! Cannot make the secret dish." << std::endl;
        return false;
    }
}

int ItalianChef::makePizza() {
    int flourPizzas = flour / 5;
    int waterPizzas = water / 5;
    return std::min(flourPizzas, waterPizzas);
}
