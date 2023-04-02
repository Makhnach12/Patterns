#include <iostream>
#include "singleton.h"
#include "builder.h"

int main() {
//    Singleton* tab1 = Singleton::getInstance();
//    tab1 -> addValues("Ford", 10);
//    Singleton* tab2 = Singleton::getInstance();
//    tab2->addValues("Chevrolet", 11);
//    tab2->print_vals();
//    std::cout<<'\n';
//    tab1->print_vals();

    Director dir;
    RomanArmyBuilder ra_builder;
    CarthaginianArmyBuilder ca_builder;

    Army * ra = dir.createArmy( ra_builder);
    Army * ca = dir.createArmy( ca_builder);
    std::cout << "Roman army:" << '\n';
    ra->info();
    std::cout << "\nCarthaginian army:" << '\n';
    ca->info();
    return 0;
}
