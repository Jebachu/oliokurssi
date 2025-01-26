#include "Chef.h"
#include "ItalianChef.h"
#include <iostream>

int main() {
    Chef chef("Gordon");
    std::cout << "Chef's name: " << chef.getName() << std::endl;
    int saladAmount = chef.makeSalad(10); // 10 ingredients
    std::cout << "Salad amount: " << saladAmount << " servings" << std::endl;

    int soupAmount = chef.makeSoup(9); // 9 ingredients
    std::cout << "Soup amount: " << soupAmount << " servings" << std::endl;

    ItalianChef italianChef("Luigi");
    std::cout << "Italian Chef's name: " << italianChef.getName() << std::endl;

    std::string inputPassword;
    std::cout << "Enter password for secret dish: ";
    std::cin >> inputPassword;

    italianChef.askSecret(inputPassword, 10, 10);  // salasana vaaditaan

    return 0;
}
