#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength)
    :type(type), name(name), health(health), attackStrength(attackStrength) {
}
   
HeroType Character::getType() const {
    return type;
}
   
const string & Character::getName() const {
    return name;
}
   
int Character::getHealth() const {
    return static_cast<double>(health);
}
   
void Character::setHealth(double h) {
    health = h;
}
   
bool Character::isAlive() const {
    if (getHealth() > 0) {
        return true;
    }
    else {
        return false;
    }
}

void Character::damage(double da) {
    setHealth(this->health - da);
}