# Calculating Coefficient of Lift

This program calculates the coefficient of lift for a given angle of attack based on wind tunnel data stored in a file.

## Program Steps
1. Ask the user for the name of file that contains the wind tunnel data.
2. Read wind-tunnel data into two parallel vectors, one vector stores the flight-path angle and the other stores the corresponding coefficient of lift for that angle. Both vectors should store doubles.
3. Ask the user for a flight-path angle. If the angle is within the bounds of the data set, the program should then use linear interpolation (see explanation of linear interpolation below) to compute the corresponding coefficient of lift and output it.
4. Finally, ask the user if they want to enter another flight-path angle. Repeat steps 3 and 4 if they answer yes, otherwise end the program if they answer no.
For linear interpolation to work, the flight-path angles in the data file must be in ascending order. If the flight-path angles are not in ascending order, your program will need to sort them before implementing Step 3.
