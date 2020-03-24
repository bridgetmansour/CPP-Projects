#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &jerseyNumber, const vector<int> &rating) {
   cout << "ROSTER" << endl;
   for (unsigned int i = 0; i < jerseyNumber.size(); i++) {
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << rating.at(i)<< endl;
   }
   cout << endl;
}

void addPlayer(vector<int> &addedJerseyNumber, vector<int> &addedRating) {
   int aJN;
   int aR;
   cout << "Enter another player's jersey number:" << endl;
   cin >> aJN;
   addedJerseyNumber.push_back(aJN);
   cout << "Enter another player's rating:" << endl;
   cin >> aR;
   addedRating.push_back(aR);
   cout << endl;
}

void removePlayer(vector<int> &removedJerseyNumber, vector<int> &removedRating) {
   int deletedPlayer;
   vector <int> copyRJN (0);
   vector <int> copyRR (0);   
   cout << "Enter a jersey number:" << endl;
   cin >> deletedPlayer;
   for (unsigned int i = 0; i < removedJerseyNumber.size(); i++) {
      if (removedJerseyNumber.at(i) != deletedPlayer) {
         copyRJN.push_back(removedJerseyNumber.at(i));
         copyRR.push_back(removedRating.at(i));
      }
   }
   removedJerseyNumber = copyRJN;
   removedRating = copyRR;
}

void updatePlayerRating(const vector<int> &updatedJerseyNumber, vector<int> &updatedRating) {
   int chosenJerseyNumber;
   int newRating;
   cout << "Enter a jersey number:" << endl;
   cin >> chosenJerseyNumber;
   cout << "Enter a new rating for the player:" << endl;
   cin >> newRating;
   for (unsigned int i = 0; i < updatedJerseyNumber.size(); i++) {
      if (updatedJerseyNumber.at(i) == chosenJerseyNumber) {
         updatedRating.at(i) = newRating;
      }
   }
}

void outputPlayersAboveRating(const vector<int> &aboveJN, const vector<int> &aboveR) {
   int ra;
   cout << "Enter a rating:";
   cin >> ra;

   cout << "ABOVE " << ra << endl;
   for (unsigned int i = 0; i < aboveJN.size(); i++) {
     if (aboveR.at(i) > ra) {
        cout << "Player " << i + 1 << " -- Jersey number: " << aboveJN.at(i) << ", Rating: " << aboveR.at(i) << endl;
     }
   }
   cout << endl;
}


int main() {

   vector <int> jerseyNumber (5);
   vector <int> rating (5);
   char optionChosen;
   
   for (unsigned int i = 0; i < 5; i++) {
      cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
      cin >> jerseyNumber.at(i);
      cout << "Enter player " << i + 1 << "'s rating:" << endl;
      cin >> rating.at(i);
      cout << endl;
   }
  
   outputRoster(jerseyNumber, rating);
  
  backToMenu:
   cout << "MENU" << endl;
   cout << "a - Add player" << endl;
   cout << "d - Remove player" << endl;
   cout << "u - Update player rating" << endl;
   cout << "r - Output players above a rating" << endl;
   cout << "o - Output roster" << endl;
   cout << "q - Quit" << endl;

   cout << endl;

   cout << "Choose an option:" << endl;
   cin >> optionChosen;
   
   if (optionChosen == 'q') {
      return 0;
   }
   
   if (optionChosen == 'o') {
      outputRoster(jerseyNumber, rating);
      goto backToMenu;
   }
   
   if (optionChosen == 'a') {
      addPlayer(jerseyNumber, rating);
      goto backToMenu;
   }
   if (optionChosen == 'd') {
      removePlayer(jerseyNumber, rating);
      goto backToMenu;
   }
   if (optionChosen == 'u') {
      updatePlayerRating(jerseyNumber, rating);
      goto backToMenu;
   }
   if (optionChosen == 'r') {
      outputPlayersAboveRating(jerseyNumber, rating);
      goto backToMenu;
   }
   
   return 0;
}