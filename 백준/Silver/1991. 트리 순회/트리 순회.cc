#include <iostream>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
constexpr int root_node = 0;
constexpr int left_node = 1;
constexpr int right_node = 2;
constexpr int MAX = 26;
int graph[MAX][3];

void preorder_traversal(int cur) {

	// 루트 -> 왼쪽 -> 오른쪽
	char c = cur + 'A';
	cout << c;
	if (graph[cur][left_node] != -1) preorder_traversal(graph[cur][left_node]);
	if (graph[cur][right_node] != -1) preorder_traversal(graph[cur][right_node]);

	return;
}

void inorder_traversal(int cur) {

	// 왼쪽 -> 루트 -> 오른쪽
	if (graph[cur][left_node] != -1) inorder_traversal(graph[cur][left_node]);
	char c = cur + 'A';
	cout << c;
	if (graph[cur][right_node] != -1) inorder_traversal(graph[cur][right_node]);

	return;
}

void postorder_traversal(int cur) {

	// 왼쪽 -> 오른쪽 -> 루트
	if (graph[cur][left_node] != -1) postorder_traversal(graph[cur][left_node]);
	if (graph[cur][right_node] != -1) postorder_traversal(graph[cur][right_node]);
	char c = cur + 'A';
	cout << c;

	return;
}

int main() {
	fast_output;

	int n;
	cin >> n;

	// 정렬이 안 된 상태로 입력이 들어오므로
	// 순서 상관 없이 입력을 받음
	char root, left, right;
	for (int i = 0; i < n; i++) {
		cin >> root >> left >> right;

		graph[root - 'A'][root_node] = root - 'A';

		if (left == '.') graph[root - 'A'][left_node] = -1;
		else graph[root - 'A'][left_node] = left - 'A';

		if (right == '.') graph[root - 'A'][right_node] = -1;
		else graph[root - 'A'][right_node] = right - 'A';
	}

	preorder_traversal(graph[0][0]);
	cout << '\n';

	inorder_traversal(graph[0][0]);
	cout << '\n';

	postorder_traversal(graph[0][0]);
	cout << '\n';

	return 0;
}