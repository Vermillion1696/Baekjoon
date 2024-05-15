#include <iostream>
#include <stack>
using namespace std;

// 숫자 배열
int arr[100000];

// +, - 출력 저장 배열
int outputArr[500000] = { 0, };
int outputIndex = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 스택 선언, 개수 저장
	stack<int> s;
	int n;
	cin >> n;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// tf : NO인지 아닌지
	// num : 다음 push시 입력되는 수
	// top : s.size()가 empty일 때의 임시 s.top() (target은 모두 자연수이다)
	bool tf = 1;
	int num = 1;
	int top;
	for (int i = 0; i < n; i++) {
		
		// 목표값 세팅
		int target = arr[i];
		
		// 스택 안이 비어있으면 top = 0, 아니면 top = s.top()
		if (s.size() == 0) {
			top = 0;
		}
		else {
			top = s.top();
		}

		// push일 때 들어오는 숫자가 target보다 큰데 제일 윗 값이 target보다 작으면 불가능 판정
		if (num > target && top < target) {
			tf = 0;
			break;
		}

		// top < target인 경우 top == target까지
		while (top < target) {
			s.push(num);
			top = s.top();
			num++;
			outputArr[outputIndex] = 1;
			outputIndex++;
		}

		// top > target인 경우 top == target까지
		while (top > target) {
			s.pop();
			top = s.top();
			outputArr[outputIndex] = -1;
			outputIndex++;
		}

		// top == target이므로 목표값 출력
		s.pop();
		if (s.size() == 0) {
			top = 0;
		}
		else {
			top = s.top();
		}
		outputArr[outputIndex] = -1;
		outputIndex++;
	}

	// 불가능일 때
	if (!tf) {
		cout << "NO";
	}

	// 가능일 때
	else {
		int index = 0;

		while (outputArr[index] != 0) {
			if (outputArr[index] == 1) {
				cout << "+\n";
				index++;
			}
			else if (outputArr[index] == -1) {
				cout << "-\n";
				index++;
			}
		}
	}

	return 0;
}