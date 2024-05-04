#include <iostream>
using namespace std;


/*example of a menu that allows the user to choose a grade of pet food using
a switch statement (a switch is just another version of if-else so any switch
could also be written as an if-else*/
int main()
{
  //variable to hold the user's selection for the switch
  char feedGrade;

  cout << "Our dog food is available in three grades: a, b, and c.\n";
  cout << "Please choose the grade you would like pricing information for: ";
  cin >> feedGrade;

  /*switch prints pricing information to the screen depending on the grade they chose
  notice a switch must always be based on a value (a char evaluates to a value so is OK)*/
  switch(feedGrade)
  {
     //all of the code next to case a is executed throught the break statement
     //if the user chooses that case...in this program 'a','b', or 'c'
     case 'a':  cout << "Grade a food is 30 cents per pound."
                     << endl;
                //note a break is required to end each case
                break;

     case 'b':  cout << "Grade b food is 15 cents per pound."
                     << endl;
                break;

    case 'c':  cout << "Grade c food is 10 cents per pound."
                    << endl;
                break;

    //the default case executes if the user enters a choice that is not
    //one fo the options ('a','b', or 'c')
    default:  cout << "That is an invalid choice.\n";
  }

  system("PAUSE");
  return 0;

}
