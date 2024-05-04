//Luis Guzman
//CSIS 135
//Homework 5
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//declare prototype functions
int countWords(string);
int countConsonants(string);
string toUpperCase(string);

int main(){
//declare variables
char selection;
string inversedStr;
string reversedStr;
string userString;
int consonantCount;
int wordCount;

do{
//print prompt to the screen
cout << "\tWelcome to String Manipulator" << endl
	<< "---------------------------------------------------" << endl
	<<"Please enter any string of characters." << endl;
//get users input save it to a variable
getline(cin, userString);
	//input validations
	if(userString == "" || userString == " "){
	cout << "Make sure you entered a string.\nTry again." << endl;
	getline(cin, userString);
	}
}while(userString == "" || userString == " ");
//new line
cout << "\n";

do{
//print the menu to the string
cout << "\tUSE THIS MENU TO MANIPULATE YOUR STRING" << endl
<< "---------------------------------------------------" << endl
<< "1) Inverse The String" << endl
<< "2) Reverse The String" << endl
<< "3) Convert The String To Uppercase" << endl
<< "4) Count Number Of Words" << endl
<< "5) Count Number Of Consonants" << endl
<< "6) Enter A Different String" << endl
<< "7) Print The String" << endl
<< "Q) Quit" << endl
<< "\nPlease make a selection." << endl;
//save users selection to a variable
cin >> selection;
//clear the \n from the keyboard buffer
cin.ignore();
//print line
cout << "\n";

//evaluate the input
if(selection == 'q' || selection == 'Q'){
	cout << "The program will now exit." << endl;
}
if(selection < '1' && selection > '7'){
		cout << "You have entered an invalid value." << endl
		<< "Please try again." << endl;
		}
switch(selection){
case '1':
inversedStr = "";//to clear any previous string.
//loop the entire length of the string
for(int i = 0; i < userString.length(); i++){
	//analyze if the string has characters that are numbers between 0 and 9
	if(userString.at(i) >= '0' && userString.at(i) <= '9'){
	//don't do anything to the characters
	inversedStr = userString;
	}
	//if the string has characters that are uppercase
	else if(isupper(userString.at(i))){
	//add the uppercase character to the previous character
	inversedStr += char (tolower((userString.at(i))));
	}
	//if the string has characters that are lowercase
	else if(islower(userString.at(i))){
	//add the lowercase character to the previous character
	inversedStr += char (toupper((userString.at(i))));
	}
	//if the string has characters that are spaces
	else if(isspace(userString.at(i))){
	//add them and save to the previous characters
	inversedStr += " ";
	}
	//if it is any other symbol don't do anything
	else
	inversedStr != userString;
}
//save the inversed string to userString
userString = inversedStr;
	break;

	case '2':
	reversedStr = "";//to clear any previous string
		//loop the entire length of the string but in the negative direction
		for(int i = userString.length() - 1; i >= 0; i--){
		//get strings character and add it to the previous character
		reversedStr += userString[i];
		}
	//save the reveresed string to userString
	userString = reversedStr;
	break;

	case '3':
	//call the function and save result to the userString variable
	userString = toUpperCase(userString);
	break;

	case '4':
	//call the function and save the result to the wordCount variable
	wordCount = countWords(userString);
	//print the number of words to the screen
	cout << "The number of words in the string is " << wordCount << ".\n" << endl;
	break;

	case '5':
	//call the function and save the result to the consonantCount variable
	consonantCount = countConsonants(userString);
	//print the number of consonants to the screen.
	cout << "The number of consonants in the string is " << consonantCount << ".\n" << endl;
	break;

	case '6':
	//prompt the user to enter a new string
	cout << "Please enter the new string." << endl;
	//save the users input to the userString variable
	getline(cin, userString);
	break;

	case '7':
	//print the userString to the string
	cout << userString << "\n"<< endl;
	break;
	}
//loop while input is not q
}while(selection != 'q' && selection != 'Q');
system("PAUSE");
return 0;
}
//####################################################################
//count the words in the string
int countWords(string userString){
//declare variables
int numWords = 0;
char stringChar;
//loop for the length of the string
for(int i = 0; i <= userString.length(); i++){
	stringChar = userString[i];
	//if the string contains a space or a \0 return a word.
	if(isspace(stringChar) || userString[i] == '\0'){
	numWords++;
	}
}
return numWords;
}
//###################################################################
//function to count the consonant
int countConsonants(string userString){
//declare variables
int consonantCount = 0;
	//loop for the length of the string
	for (int i = 0; i < userString.length(); i++){
		//returns 0 if the string is a number
		if(userString.at(i) >= '0' && userString.at(i) <= '9'){
		return consonantCount;
		}
		//count consonants only when they're not consonants
		if(userString.at(i) != 'a' && userString.at(i) !='A')
		if(userString.at(i) != 'e' && userString.at(i) !='E')
		if(userString.at(i) != 'i' && userString.at(i) != 'I')
		if(userString.at(i) != 'o' && userString.at(i) != 'O')
		if(userString.at(i) != 'u' && userString.at(i) != 'U')
		if(userString.at(i) != ' ' && userString.at(i) != '\0')
		if(userString.at(i) != '.' && userString.at(i) != ',')
	consonantCount++;
	}
return consonantCount;
}
//##################################################################
//function to convert the string to upper case
string toUpperCase(string userString){
	//loop for the length of the string
	for(int i = 0; i < userString.length(); i++){
	//convert the chars to uppercase
	userString[i] = toupper(userString[i]);
	}
return userString;
}
