#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    if (n2 % 2 == 1) {
        n2 = n2 / 2 + 1;
    }
    else {
        n2 = n2 / 2;
    }

    if (n1 >= n2) {
        cout << "E";
    }
    else {
        cout << "H";
    }

    return 0;
}