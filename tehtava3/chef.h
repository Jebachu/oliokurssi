#ifndef CHEF_H
#define CHEF_H

#include <string>

class Chef {
private:
    std::string chefName;

public:
    Chef(const std::string& name);
    ~Chef();

    std::string getName() const;
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);
};

#endif // CHEF_H
