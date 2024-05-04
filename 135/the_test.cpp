
#include <iostream>
#include <iomanip>

using namespace std;

char symbol;
int columns;
int rows;
const char spacer(' ');

void horizSide(const int len, const char c, const char spacer);

int main(int argc, char *argv[]) {
    int size;
    cout << "Enter symbol ";
    cin >> symbol;
	cout << "Enter rows" << endl;
	cin >> rows;
	cout << "Enter columns" << endl;
	cin >> columns;
    horizSide(size,symbol,spacer);
    for (int i = 0; i < size-2; i++) {
        cout << symbol << setw(size*2-2);
        cout << setfill(spacer) << symbol << endl;
    }
    horizSide(size,symbol,spacer);
    system("PAUSE");
	return 0;
}

void horizSide(const int len, const char c, const char spacer) {
    for (int i = 0; i < len-1; i++) {
        cout << c << spacer;
    }
    cout << c << endl;
}
