#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum (const string & filename) {
   ifstream inFS;
   int number;
   int sum = 0;

   inFS.open(filename);

   if (!inFS.is_open()) {
   cout << "Error opening " << filename << endl;
   exit(1);
   }

   while (inFS >> number) {
   sum = sum + number;
   }

   return sum;
}

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}