#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include "Character.h"
#include <iostream>
#include <string>

class Warrior : public Character {
 private:
    std::string allegiance;
 public:
    Warrior(const std::string &name, double health, double attackStrength, const std::string &i);
    void attack(Character &opponent);
};

#endif