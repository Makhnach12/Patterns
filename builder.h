//
// Created by Никита on 30.03.2023.
//

#ifndef PATTERNS_BUILDER_H
#define PATTERNS_BUILDER_H

#include <iostream>
#include <vector>

class Unit{
public:
    virtual void info() {};
    int num{0};
};



// Классы всех возможных родов войск
class Infantryman: public Unit{
public:
    void info() override {
        if (num) {
            std::cout << "Infantryman" << '\n';
        }
    }
};

class Archer: public Unit{
public:
    void info() override {
        if (num) {
            std::cout << "Archer" << '\n';
        }
    }
};

class Horseman: public Unit{
public:
    void info() override {
        if (num) {
            std::cout << "Horseman" << '\n';
        }
    }
};

class Catapult: public Unit{
public:
    void info() override {
        if (num) {
            std::cout << "Catapult" << '\n';
        }
    }
};

class Elephant: public Unit{
public:
    void info() override {
        if (num) {
            std::cout << "Elephant" << '\n';
        }
    }
};


// Класс "Армия", содержащий все типы боевых единиц
class Army
{
public:
    Infantryman vi;
    Archer va;
    Horseman vh;
    Catapult vc;
    Elephant ve;

    void info() {
        vi.info();
        va.info();
        vh.info();
        vc.info();
        ve.info();
    }
};


// Базовый класс ArmyBuilder объявляет интерфейс для поэтапного
// построения армии и предусматривает его реализацию по умолчанию

class ArmyBuilder
{
protected:
    Army* p;
public:
    ArmyBuilder(): p(nullptr) {}
    virtual ~ArmyBuilder() = default;
    virtual void createArmy() {}
    virtual void buildInfantryman() {}
    virtual void buildArcher() {}
    virtual void buildHorseman() {}
    virtual void buildCatapult() {}
    virtual void buildElephant() {}
    Army* getArmy() { return p; }
};


// Римская армия имеет все типы боевых единиц кроме боевых слонов
class RomanArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() override { p = new Army; }
    void buildInfantryman() override { p->vi.num += 1; }
    void buildArcher() override { p->va.num += 1; }
    void buildHorseman() override { p->vh.num += 1; }
    void buildCatapult() override { p->vc.num += 1; }
};


// Армия Карфагена имеет все типы боевых единиц кроме катапульт
class CarthaginianArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() override { p = new Army; }
    void buildInfantryman() override { p->vi.num += 1; }
    void buildArcher() override { p->va.num += 1; }
    void buildHorseman() override { p->vh.num += 1; }
    void buildElephant() override { p->ve.num += 1; }
};


// Класс-распорядитель, поэтапно создающий армию той или иной стороны.
// Именно здесь определен алгоритм построения армии.
class Director
{
public:
    Army* createArmy( ArmyBuilder & builder )
    {
        builder.createArmy();
        builder.buildInfantryman();
        builder.buildArcher();
        builder.buildHorseman();
        builder.buildCatapult();
        builder.buildElephant();
        return(builder.getArmy());
    }
};


#endif //PATTERNS_BUILDER_H
