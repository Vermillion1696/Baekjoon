#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n >= 620 && n <= 780) {
        cout << "Red";
    }
    else if (n >= 590 && n < 620) {
        cout << "Orange";
    }
    else if (n >= 570 && n < 590) {
        cout << "Yellow";
    }
    else if (n >= 495 && n < 570) {
        cout << "Green";
    }
    else if (n >= 450 && n < 495) {
        cout << "Blue";
    }
    else if (n >= 425 && n < 450) {
        cout << "Indigo";
    }
    else {
        cout << "Violet";
    }

    return 0;
}