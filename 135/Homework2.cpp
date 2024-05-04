//Luis Guzman
//CSIS 135
//Homework #2
//Pseudocode: Print title and brief descripttion to the screen. Print the menu to the screen and prompt user
//for input. Evaluate the user input. if input is a through h ask user for his/her weight.
//save user input. Prompt the user for their desired travel speed. Save their input.
//Evaluate user input for each possible selection of a through h, calculate weight and distance
//calculate the travel time in hours. print the information: Planet travled to, user's weight on
//that planet. distance traveled in hours, days and years

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables
	char input;
	string planet;
	double earthWeight = 0;
	double newWeight = 0;
	double speed = 0;
	double travelTime = 0;
	double distancePlanet = 0;
	const double DISTANCE = 93000000;
	//print the title and info on screen
	cout << "INTERPLANETARY TRAVEL" << endl
		<<"-------------------------" << endl
		<<"\nWelcome to INTERPLANETARY TRAVEL!" << endl
		<< "This program will calculate the time travel based on distance, your\n"
		"weight and your preferred travelling speed." << endl;
		//print the menu on screen
		cout << "\n\n\nINTERPLANETARY TRAVEL" << endl
			<< "-------------------------" << endl
			<< "a) Mercury" << endl
			<< "b) Venus" << endl
			<< "c) Earth" << endl
			<< "d) Mars" << endl
			<< "e) Jupiter" << endl
			<< "f) Saturn" << endl
			<< "g) Uranus" << endl
			<< "h) Neptune" << endl
			<< "q) Quit" << endl
			<< endl
			//prompt user for input
			<< "Please select a planet between a through h or enter q to exit." << endl;
		//save user input
		cin >> input;
		//evaluate user input
		if(input >= 'a' && input <= 'h'){
			//prompt user for weight
			cout << "\nPlease enter your weight to calculate a safe trip." << endl;
			//save input
			cin >> earthWeight;
			//prompt user for desired traveling speed
			cout << "\nPlease enter the speed, in miles per hour, that you would like to travel" << endl;
			//save input
			cin >> speed;
				//save planet name to planet. Calculate new weight and Calculate distance
				//for each individual case.
				if(input == 'a'){
				planet = "Mercury";
				newWeight = earthWeight * 0.27;
				distancePlanet = DISTANCE - 36000000;
				}//if
				else if(input == 'b'){
				planet = "Venus";
				newWeight = earthWeight * 0.86;
				distancePlanet = DISTANCE - 67000000;
				}//else if
				else if(input == 'c'){
				planet = "Earth";
				newWeight = earthWeight * 1.00;
				distancePlanet = DISTANCE - 93000000;
				}//else if
				else if(input == 'd'){
				planet = "Mars";
				newWeight = earthWeight * 0.37;
				distancePlanet = DISTANCE - 141000000;
				}//else if
				else if(input == 'e'){
				planet = "Jupiter";
				newWeight = earthWeight * 2.64;
				distancePlanet = DISTANCE - 483000000;
				}//else if
				else if(input == 'f'){
				planet = "Saturn";
				newWeight = earthWeight * 1.17;
				distancePlanet = DISTANCE - 886000000;
				}//else if
				else if(input == 'g'){
				planet = "Uranus";
				newWeight = earthWeight * 0.92;
				distancePlanet = DISTANCE - 1782000000;
				}//else if
				else if(input == 'h'){
				planet = "Neptune";
				newWeight = earthWeight * 1.44;
				distancePlanet = DISTANCE - 2793000000;
				}//else if
				//calculate travel time in hours
				travelTime = distancePlanet / speed;
				//print the formatted information
				cout << "\n\nINTER PLANETARY TRAVEL: Earth to " << planet << endl
					<< "-----------------------------------------" << endl
					//prints formatted calculated weight
					<< "Your weight on " << planet << ": "<< fixed << setprecision(2) << setw(9) << newWeight << " lbs" << endl
					//print the planet name
					<< "\nYour travel time to " << planet << ":" << endl
					//print travel time in hours
					<< "In Hours: " << fixed << setprecision(0) << abs(travelTime) << " hours" << endl
					//print travel time in days
					<< "In Days: " << fixed << setprecision(0) << abs(travelTime / 24) << " days" << endl
					//print travel time in years
					<< "In Years: " << fixed << setprecision(2) << abs((travelTime / 24) / 365) << " years\n" << endl;
		}//if
		//input validation (which only works once)
		else if(input == 'q'){
			cout << "Program will now quit." << endl;
		}//else if
		else{
			cout << "You've entered a wrong selection." << endl;
		}//else
	system("PAUSE");
	return 0;
}//main()
