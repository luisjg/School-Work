

//Luis Guzman
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
cout << "Seats";
for(int i = 0; i < 20; i++){
cout << setw(3) << i;
}
cout << endl;
for(int i = 0; i < 20; i++){
for(int j = 0; j < 15; j++){
cout << setw(3) << "*";
}
}
//cout << endl;
for(int j = 0; j < 15; j++){
cout << "Row " << setw(4) << j << endl;
}
//system("PAUSE");
return 0;
}
