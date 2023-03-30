//
// Created by Никита on 30.03.2023.
// Суть паттерна проста - сдлеать тву чтоб можно было создать только 1 экземпляр класса
//

#ifndef PATTERNS_SINGLETON_H
#define PATTERNS_SINGLETON_H
#include <vector>
#include <string>
#include <iostream>


class Singleton {
private:
    std::vector<std::pair<std::string,int>> table;
    Singleton(){;}
    //is private(because of this we can't сall it and create new copy)
    static Singleton *instance_ptr;
public:
    //person couldn't create another class because we delete all hints(20 and 22 lines)
    Singleton(const Singleton&) = delete;
    ~Singleton(){ delete instance_ptr; }
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance();
    void addValues(std::string name, int num){ this->table.emplace_back(name, num); }
    void print_vals();
};


#endif //PATTERNS_SINGLETON_H
