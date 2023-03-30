#include <iostream>
#include "singleton.h"

int main() {
    Singleton* tab1 = Singleton::getInstance();
    tab1 -> addValues("Ford", 10);
    Singleton* tab2 = Singleton::getInstance();
    tab2->addValues("Chevrolet", 11);
    tab2->print_vals();
    std::cout<<'\n';
    tab1->print_vals();
    return 0;
}
