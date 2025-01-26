#include "Chef.h"
#include <iostream>

Chef::Chef(const std::string& name) : chefName(name) {
    std::cout << "Chef " << chefName << " konstruktori." << std::endl;
}

Chef::~Chef() {
    std::cout << "Chef " << chefName << " destruktori." << std::endl;
}

std::string Chef::getName() const {
    return chefName;
}

int Chef::makeSalad(int ingredients) {
    int servings = ingredients / 5;
    std::cout << "Making salad with " << ingredients << " ingredients. Servings: " << servings << std::endl;
    return servings;
}

int Chef::makeSoup(int ingredients) {
    int servings = ingredients / 3;
    std::cout << "Making soup with " << ingredients << " ingredients. Servings: " << servings << std::endl;
    return servings;
}
