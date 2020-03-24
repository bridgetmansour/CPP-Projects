#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt (const string &filename, char ch) {
   ifstream inFS;
   int count = 0;
   char input;
   inFS.open(filename);
   
   if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
   }
   
   int spaces = 0;
   while (inFS >> input) {
      
      if (ch == ' ') {
        inFS.get(ch);
        spaces++;
      }
      
      if (input == ch) {
         count++;
      }
   }
   
   inFS.close();
   
   return count;
}


int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}
