#include <iostream>
#include <unordered_map>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast_output;

    long long int 땅_개수;
    cin >> 땅_개수;

    long long int 병사_수, 병사_값;
    while (땅_개수--) {
        unordered_map<long long int, long long int> 맵;
        cin >> 병사_수;

        for (long long int 반복 = 0; 반복 < 병사_수; 반복++) {
            cin >> 병사_값;
            맵[병사_값]++;
        }

        long long int 최대_병사 = -1, 최대_병사_종류 = -1;
        bool 동점_여부 = false;

        for (auto& 병사 : 맵) {
            if (병사.second > 최대_병사) {
                최대_병사 = 병사.second;
                최대_병사_종류 = 병사.first;
                동점_여부 = false;
            }
            else if (병사.second == 최대_병사) {
                동점_여부 = true;
            }
        }

        if (최대_병사 > 병사_수 / 2 && !동점_여부) {
            cout << 최대_병사_종류 << "\n";
        }
        else {
            cout << "SYJKGW\n";
        }
    }

    return 0;
}
