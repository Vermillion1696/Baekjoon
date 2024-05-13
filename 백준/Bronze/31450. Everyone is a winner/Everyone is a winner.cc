#include <iostream>
using namespace std;

int main()
{
    int m, k;
    cin >> m >> k;
    if (m % k == 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}