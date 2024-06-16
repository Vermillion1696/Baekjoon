#include <iostream>
using namespace std;

int gcd(int a, int b) { // 최대 공약수
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { // 최소 공배수
    return (a * b) / gcd(a, b);
}
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int endx, endy, targetx, targety;
        int result = -1;
        cin >> endx >> endy >> targetx >> targety;

        // 멸망해는 최소공배수
        int maxi = lcm(endx, endy);

        // targetx부터 시작해 endx를 아무리 더해도 currentx == targetx
        for (int i = targetx; i <= maxi; i += endx) {
            int currenty = i % endy;

            // 나머지가 0이면 y == endy
            if (currenty == 0) {
                currenty = endy;
            }

            // currenty == targety면 x, y 모두 targetx, targety임
            if (currenty == targety) {
                result = i;
                break;
            }
        }
        cout << result << '\n';
    }
    return 0;
}
