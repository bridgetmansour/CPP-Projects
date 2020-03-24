#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData (string inputFile, vector <double> &flightPathAngle, vector <double> &coefficientOfLift) {
  
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   
   // Verify file opened correctly.
   // and
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }  
   
   // Read in integers from input file to vector.
   double num;
   int counter = 0;
   while (inFS >> num) {
      
      if (counter == 0) {
         flightPathAngle.push_back(num);
         counter = 1;
      }
      else {
         coefficientOfLift.push_back(num);
         counter = 0; 
      }
   }
   
   inFS.close();
   
}

bool isOrdered (vector <double> flightPathAngle) {
   bool soFarSoGood;
   
   if (flightPathAngle.size() < 2) {
      return true;
   }
   
   for (unsigned int i = 1; i < flightPathAngle.size(); i++) {
         if (flightPathAngle.at(i - 1) <= flightPathAngle.at(i)) {
            soFarSoGood = true;
         }
         else {
            return false;
         }
   
   }
   return soFarSoGood;
}

void reorder (vector <double> &flightPathAngle, vector <double> &coefficientOfLift) {
   
   top:
   for (unsigned int i = 1; i < flightPathAngle.size(); i++) {
      
      if (flightPathAngle.at(i-1) > flightPathAngle.at(i)) {
         
         double placeholderA = flightPathAngle.at(i-1);
         double placeholderB = coefficientOfLift.at(i-1);
         flightPathAngle.at(i-1) = flightPathAngle.at(i);
         coefficientOfLift.at(i-1) = coefficientOfLift.at(i);
         flightPathAngle.at(i) = placeholderA;
         coefficientOfLift.at(i) = placeholderB;
         goto top;
      }
      
   }
   
}

double interpolation (double inputPathAngle, vector <double> flightPathAngle, vector <double> coefficientOfLift) {
   
      if ( inputPathAngle < flightPathAngle.at(0) && inputPathAngle > flightPathAngle.at(flightPathAngle.size())) {
      exit(1);
      }
      
      double previousAngle = flightPathAngle.at(0);
      double output;
      
      for (unsigned int i = 0; i < flightPathAngle.size(); i++) {
         if (inputPathAngle == flightPathAngle.at(i)) {
            output = coefficientOfLift.at(i);
            return output;
         }
         if (inputPathAngle > previousAngle && inputPathAngle < flightPathAngle.at(i)) {
            output = coefficientOfLift.at(i - 1) + ((inputPathAngle - previousAngle)/(flightPathAngle.at(i) - previousAngle))*(coefficientOfLift.at(i) - coefficientOfLift.at(i-1));
            return output;
         }
         else {
            previousAngle = flightPathAngle.at(i);
         }
      }
      
      return 0;
}

int main() {
   
   string inputFile;
   cout << "Enter name of input data file:";
   cout << endl;
   cin >> inputFile;
   cout << endl;
   vector <double> Angle;
   vector <double> Lift;
   
   readData(inputFile, Angle, Lift);
   
   bool inOrder;
   inOrder = isOrdered(Angle);
   cout << inOrder;
   
   double inputAngle;
   cin >> inputAngle;
   cout << endl;
   
   double liftC = interpolation(inputAngle, Angle, Lift);
   cout << liftC;
   
   return 0;
}