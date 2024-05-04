#include <iostream>
using namespace std;

int main()
{
 	int age = 40;

//this not only causes the wrong if statement to
//execute but assigns the value 30 to age 
if(age = 30)
 {
        cout << "Happy Birthday Incorrect." << endl;
        cout << "Age is " << age << endl;
 }

 if(age == 40)
 {
        cout << "Happy Birthday Correct." << endl;
 }

 	system("PAUSE");
 	return 0;
}

