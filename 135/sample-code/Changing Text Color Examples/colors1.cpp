#include <iostream>
#include <cstdlib>
#include <windows.h>  //include windows library
using namespace std;

int main()
{
    //create a handle to the standard output screen
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    
    //Write 16 lines of text in different colors
    for(int color = 0; color < 16; color++)
    {
            //set the text color, remains in effect until changed
            //in the next loop cycle
            SetConsoleTextAttribute(screen, color);
            
            cout << "Hello World!" << endl;
    }
    
    //Restore the normal text color
    SetConsoleTextAttribute(screen, 7);
    system("PAUSE");
    return 0;
}
