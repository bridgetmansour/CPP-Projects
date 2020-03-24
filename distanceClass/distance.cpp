#include "Distance.h"

Distance::Distance() {
   
   feet = 0;
   inches = 0.0;
   init();
   
}

Distance::Distance(unsigned ft, double in) {
   
   feet = ft;
   inches = in;
   init();
   
}

Distance::Distance(double in) {
 
   feet = 0;
   inches = in;
   init();
   
}

unsigned int Distance::getFeet() const {
   
   return feet;
}

double Distance::getInches() const {
  
   return inches;
}

double Distance::distanceInInches() const {

   return inches + (feet * 12);
}

double Distance::distanceInFeet() const {
   
   double totalFeet;
   double totalDistanceInInches = (feet * 12.0) + inches;
   totalFeet = totalDistanceInInches / 12.0;
   
   return totalFeet;
}

double Distance::distanceInMeters() const {
   
   double totalMeters;
   double totalDistanceInInches = (feet * 12.0) + inches;
   totalMeters = totalDistanceInInches * 0.0254;
   
   return totalMeters;
}

const Distance Distance::operator+(const Distance &rhs) const {
   
   Distance sum;
   sum.feet = feet + rhs.feet;
   sum.inches = inches + rhs.inches;
   sum.init();
   
   return sum;
}

const Distance Distance::operator-(const Distance &rhs) const {
   
   Distance difference;
   if (distanceInInches() > rhs.distanceInInches()) {
      difference = distanceInInches() - rhs.distanceInInches();
   }
   else {
      difference = rhs.distanceInInches() - distanceInInches();
   }
   difference.init();
   
   return difference;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
   
   out << rhs.feet << "\' " << rhs.inches << "\"";
   return out;
   
}

   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */
void Distance::init() {
   
   if (inches < 0) {
      inches = (-1) * inches;
   }
   while (inches >= 12) {
      inches = inches - 12;
      feet = feet + 1;
   }
   
}