#include <iostream>
#include <stack>
using namespace std;

// 다음 target과 일치하는 순번을 빼내는 함수
void popNext(stack<int>& linea, stack<int>& lineb, int target, bool& tf) {
	while (1) {
		// linea(우측)이 안 비었고 target과 같으면
		if (!linea.empty() && linea.top() == target) {
			linea.pop();
			return;
		}
		// lineb(하단)이 안 비었고 target과 같으면
		else if (!lineb.empty() && lineb.top() == target) {
			lineb.pop();
			return;
		}
		// (위 두 함수에 의해 두 라인 모두 top이 target이 아님)
		// linea(우측)이 안 비었으면 lineb(하단)으로 이동
		else if (!linea.empty()) {
			lineb.push(linea.top());
			linea.pop();
		}
		// linea가 비었고, linea lineb 모두 top이 target이 아니면 (불가능)
		else {
			tf = false;
			return;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int> linea;
	stack<int> lineb;
	int n, number;
	cin >> n;

	// lineb stack에 입력
	for (int i = 0; i < n; i++) {
		cin >> number;
		lineb.push(number);
	}

	// 입력이 앞~뒤 이므로 뒤집는게 필요함, linea에 입력
	while (!lineb.empty()) {
		linea.push(lineb.top());
		lineb.pop();
	}

	// 1번부터 n번까지 빼냄
	bool tf = true;
	for (int i = 1; i <= n; i++) {
		popNext(linea, lineb, i, tf);
		if (!tf) {
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";
	return 0;
}