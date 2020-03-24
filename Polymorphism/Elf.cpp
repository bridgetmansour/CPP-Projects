#include "Character.h"
#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
    :Character(ELF, name, health, attackStrength), familyName(family) {
}
  
void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.familyName == this->familyName) {     
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << opp.familyName << " family." << endl;   
        }
        else {
            double damageDone = (this->health / MAX_HEALTH) * (this->attackStrength) ;
            opponent.damage(damageDone);
            cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << damageDone << " damage." << endl;     
        }
    }
    else {
        double damageDone = (this->health / MAX_HEALTH) * (this->attackStrength) ;
        opponent.damage(damageDone);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;        
    }
}