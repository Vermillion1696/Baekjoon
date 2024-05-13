#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;

    a -= 24;
    cout << (b - a) % 24;

    return 0;
}