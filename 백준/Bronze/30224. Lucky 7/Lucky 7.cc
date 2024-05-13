#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tempn = n;
    int temp;
    bool tf = 0;
    for (int i = 0; i < 10; i++) {
        temp = tempn % 10;
        if (temp == 7) {
            tf = 1;
            break;
        }
        tempn /= 10;
    }

    if (!tf && n % 7 != 0) {
        cout << "0";
    }
    else if (!tf && n % 7 == 0) {
        cout << "1";
    }
    else if (tf && n % 7 != 0) {
        cout << "2";
    }
    else {
        cout << "3";
    }

    return 0;
}