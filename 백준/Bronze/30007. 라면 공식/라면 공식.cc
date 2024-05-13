#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int times;
    cin >> times;

    int a, b, x;
    for (int i = 0; i < times; i++) {
        cin >> a >> b >> x;
        cout << a * (x - 1) + b << "\n";
    }

    return 0;
}