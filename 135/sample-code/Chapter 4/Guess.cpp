#include <iostream>
#include <ctime>
using namespace std;
int main()
{
   int secretNum;
   int guess;
   bool hasWon = false;
      
   /* initialize random seed: */
  srand ( time(NULL) );

  /* generate secret number: */
  secretNum = rand() % 25 + 1;

  cout << "You will get three guesses." << endl;
  
  cout << ("Guess the number (1 to 25): ");
  cin >> guess;
    
  if (secretNum <  guess) 
     cout << "The secret number is lower" << endl;
  
  else if (secretNum > guess) 
     cout << "The secret number is higher" << endl;
  
  else
    hasWon = true;
    
  //only have them guess a second time if they didn't win
  if(!hasWon)
  {
     cout << ("Guess the number (1 to 25): ");
     cin >> guess;
     
     if (secretNum <  guess) 
        cout << "The secret number is lower" << endl;
  
     else if (secretNum > guess) 
        cout << "The secret number is higher" << endl;
  
     else
        hasWon = true;
  }
  
   //only have them guess a third time if they didn't win
  if(!hasWon)
  {
     cout << ("Guess the number (1 to 25): ");
     cin >> guess;
     
     if (secretNum <  guess) 
        cout << "The secret number is lower" << endl;
  
     else if (secretNum > guess) 
        cout << "The secret number is higher" << endl;
  
     else
        hasWon = true;
  }

  if(hasWon)
    cout << "Congratulations!  The secret number was " << secretNum << endl;
  
  else
     cout << "Sorry, the secret number was " << secretNum << endl;
      
  system("PAUSE");
  return 0;
}
