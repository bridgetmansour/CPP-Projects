#ifndef __WIZARD_H__
#define __WIZARD_H__
#include "Character.h"
#include <iostream>
#include <string>

class Wizard : public Character {

 private:
    int rank;
 public:
    Wizard( const std::string &name, double health, double attackStrength, int j);
    void attack(Character &opponent);
};

#endif