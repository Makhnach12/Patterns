//
// Created by Никита on 30.03.2023.
//

#include "singleton.h"

Singleton *Singleton ::instance_ptr = nullptr;

Singleton* Singleton::getInstance(){
    if (instance_ptr == nullptr){
        instance_ptr = new Singleton();
        return instance_ptr;
    }
    else{
        return instance_ptr;
    }
}

void Singleton::print_vals(){
    for (auto item : table){
        std::cout << item.first << ' ' << item.second << '\n';
    }
}