#include <iostream>
using namespace std;

int main()
{
    int a[] = { 12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6 };
    int b[] = { 1600,894,1327,1311,1004,1178,1357,837,1055,556,773 };
    int n;
    cin >> n;
    cout << a[n - 1] << " " << b[n - 1];
    return 0;
}