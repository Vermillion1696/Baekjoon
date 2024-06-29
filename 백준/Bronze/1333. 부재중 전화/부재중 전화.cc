#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define BLANK 5

int main() {
	int songs, length, freq, time = 0;
	cin >> songs >> length >> freq;

	// 들을 수 있는 시간 집합, 실제 벨이 울리는 시간 집합
	queue<int> able, ringing;

	while (songs--) {
		time += length;
		
		// 들을 수 있는 시간은 노래가 끝난 시점 ~ 노래가 끝난 시점 + 4
		for (int i = 0; i < 5; i++) {
			able.push(time + i);
			// cout << able.back() << " ";
		}

		time += BLANK;
	}

	// 벨이 울리는 시간을 다 넣음
	for (int i = 0; i <= 16000; i++) {
		ringing.push(i * freq);
	}
	
	// 비교하면서 작은걸 뺌, 찾으면 탈출
	while (!able.empty()) {
		if (ringing.front() == able.front()) {
			//cout << "found!" << "\n";
			cout << able.front();
			return 0;
		}
		else if (ringing.front() < able.front()) {
			//cout << "ringing : " << ringing.front() << "\n";
			ringing.pop();
		}
		else {
			//cout << "able : " << able.front() << "\n";
			able.pop();
		}
	}

	// 그게 아니라면 남은 울리는 시간중 제일 빠른게 답
	cout << ringing.front();

	return 0;
}