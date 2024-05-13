#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string s;
    while (n--) {
        cin >> s;
        if (s.compare("Algorithm") == 0) {
            cout << "204\n";
        }
        else if (s.compare("DataAnalysis") == 0) {
            cout << "207\n";
        }
        else if (s.compare("ArtificialIntelligence") == 0) {
            cout << "302\n";
        }
        else if (s.compare("CyberSecurity") == 0) {
            cout << "B101\n";
        }
        else if (s.compare("Network") == 0) {
            cout << "303\n";
        }
        else if (s.compare("Startup") == 0) {
            cout << "501\n";
        }
        else {
            cout << "105\n";
        }
    }

    return 0;
}