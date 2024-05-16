#include <iostream>
#include <queue>
using namespace std;

int main() {

	// 테스트 케이스
	int tc;
	cin >> tc;

	while (tc--) {

		// pair queue, n, m 선언
		queue<pair<int, int>> q;
		int n, m;
		cin >> n >> m;

		// index: 삽입 순서, temp: 임시 숫자 저장 공간, numCNT: 1~9가 나온 개수
		int index = 0;
		int temp;
		int numCNT[9] = { 0, };
		
		// 입력
		while (n--) {
			cin >> temp;
			numCNT[temp - 1]++;
			q.push(make_pair(temp, index));
			index++;
		}

		// 숫자가 큰 순서대로 우선순위를 부여하므로 i=8 (실제 숫자 9) 부터 검사
		int cnt = 1;
		bool tf = 0;
		for (int i = 8; i >= 0; i--) {

			// 남은 i + 1의 개수가 0일 때까지
			while (numCNT[i] > 0) {

				// q.front().first가 i + 1과 같을 때까지 뒤로 밀기
				while (q.front().first != i + 1) {
					temp = q.front().first;
					index = q.front().second;
					q.pop();
					q.push(make_pair(temp, index));
					// cout << "노드 뒤로 이동 ! value : " << temp << ", index : " << index << "\n";
				}

				// q.front().first==i+1 && q.front().second==m (num, index 둘 다 만족)
				if (q.front().second == m) {
					// cout << "노드 발견 ! value : " << q.front().first << " index : " << q.front().second << "\n";
					tf = 1;
					break;
				}
				// q.front().first==i+1 && q.front().second!=m (index가 다름)
				else {
					cnt++;
					// cout << "노드 삭제 ! value : " << q.front().first << " index : " << q.front().second << "\n";
					q.pop();
					numCNT[i]--;
				}
			}

			if (tf) {
				break;
			}
		}

		// 출력
		cout << cnt << "\n";
	}

	return 0;
}