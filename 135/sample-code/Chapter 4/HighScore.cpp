#include <iostream>
using namespace std;

int main()
{
    const int TOP_SCORE = 101999;   
 
    int score;
    bool highScore = false;
 
    cout << "Please enter your score in the game:";
    cin >> score;
 
    if(score > TOP_SCORE)
    {
       highScore = true;
    }
    
    //notice this is the same as writing if(highScore == true)
    if(highScore)
    {
       cout << "CONGRATULATIONS YOU HAVE THE NEW TOP SCORE!" << endl;
    }
    
    else
    {
       cout << "Please try again." << endl;
    }

    system("PAUSE");
    return 0;
}
