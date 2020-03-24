#ifndef __ELF_H__
#define __ELF_H__
#include "Character.h"
#include <iostream>
#include <string>

class Elf : public Character {
 private:
    std::string familyName;
 public:
    Elf(const std::string &name, double health, double attackStrength, const std::string &family);
    void attack(Character &opponent);
};

#endif