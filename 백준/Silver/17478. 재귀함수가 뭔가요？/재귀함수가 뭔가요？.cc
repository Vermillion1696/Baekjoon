#include <iostream>
#define fast_output ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// 재귀 깊이에 따른 _ 출력
void print_precondition(int depth) {
	for (int i = 0; i < depth * 4; i++) cout << '_';
	return;
}

void what_is_recursion(int depth, int do_time) {

	print_precondition(depth);
	cout << "\"재귀함수가 뭔가요?\"\n";

	// base condition
	if (depth == do_time) {
		print_precondition(depth);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	else {
		print_precondition(depth);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		print_precondition(depth);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		print_precondition(depth);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		what_is_recursion(depth + 1, do_time);
	}

	print_precondition(depth);
	cout << "라고 답변하였지.\n";

	return;
}

int main() {
	int do_time;
	cin >> do_time;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	what_is_recursion(0, do_time);

	return 0;
}