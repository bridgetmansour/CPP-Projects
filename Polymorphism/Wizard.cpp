#include "Wizard.h"
#include "Character.h"
#include <iostream>

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int j)
    :Character(WIZARD, name, health, attackStrength), rank(j) {       
}
  
void Wizard::attack(Character &opponent) {
    
    if (opponent.getType() == WIZARD) {
        Wizard& opp = dynamic_cast<Wizard&>(opponent);
        double damageDone = attackStrength * (static_cast<double>(rank) / static_cast<double>(opp.rank));  
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;  
        opponent.setHealth(opponent.getHealth() - damageDone);
    }
    else {
        double damageDone = attackStrength;
        opponent.setHealth(opponent.getHealth() - damageDone);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;        
    }  

}