#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {

	// 테스트 케이스
	int testCase;
	cin >> testCase;

	// 명령 입력 받는 compile, pop 변수 temp, 덱 deck
	string compile;
	int temp;
	deque<int> deck;

	for (int i = 0; i < testCase; i++) {
		cin >> compile;
		
		// push_back
		if (compile.compare("push_back") == 0) {
			cin >> temp;
			deck.push_back(temp);
		} // push_front
		else if (compile.compare("push_front") == 0) {
			cin >> temp;
			deck.push_front(temp);
		} // back
		else if (compile.compare("back") == 0) {
			if (deck.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << deck.back() << endl;
			}
		} // empty
		else if (compile.compare("front") == 0) {
			if (deck.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << deck.front() << endl;
			}
		} // pop_back
		else if (compile.compare("pop_back") == 0) {
			if (deck.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << deck.back() << endl;
				deck.pop_back();
			}
		} // pop_front
		else if (compile.compare("pop_front") == 0) {
			if (deck.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << deck.front() << endl;
				deck.pop_front();
			}
		} // size
		else if (compile.compare("size") == 0) {
			cout << deck.size() << endl;
		} // empty
		else if (compile.compare("empty") == 0) {
			cout << deck.empty() << endl;
		}
	}

	return 0;
}