#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> measurements(n);
    for (int i = 0; i < n; ++i) {
        cin >> measurements[i];
    }

    sort(measurements.begin(), measurements.end());
    
    int lowSize = (n + 1) / 2;
    int highSize = n / 2;

    vector<int> lowTides(measurements.begin(), measurements.begin() + lowSize);
    vector<int> highTides(measurements.begin() + lowSize, measurements.end());

    reverse(lowTides.begin(), lowTides.end());

    vector<int> result;

    for (int i = 0; i < highSize; ++i) {
        result.push_back(lowTides[i]);
        result.push_back(highTides[i]);
    }

    if (lowSize > highSize) {
        result.push_back(lowTides.back());
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ' ';
    }
    cout << endl;

    return 0;
}