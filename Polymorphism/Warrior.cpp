#include "Character.h"
#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &i)
    :Character(WARRIOR, name, health, attackStrength), allegiance(i) {
}
  
void Warrior::attack(Character &opponent) {
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.allegiance == this->allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << opp.allegiance << "." << endl;
        }
        else {
            double damageDone = (this->health / MAX_HEALTH) * (this->attackStrength) ;
            opponent.damage(damageDone);
            cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damageDone << " damage." << endl;            
        }
    }
    else {
        double damageDone = (this->health / MAX_HEALTH) * (this->attackStrength);
        opponent.damage(damageDone);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;        
    }
}