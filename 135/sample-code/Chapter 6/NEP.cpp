#include <conio.h>
#include <iostream>
using namespace std;

int main(){
    while(true){
    
    //main program goes here
   
    int ans;
    char quitChar = 'q';
    cout << "Hit '" << quitChar << "' to end the program." << endl;
    ans = getch();
    if (static_cast<char>(ans) == quitChar) return 0;
    }
    cout << endl;
}
