#include <iostream>
#include <algorithm>
using namespace std;

// 노드 구조체 define
typedef struct Node {
	int x;
	int y;
} Node;

// <algorithm> 라이브러리 내장 구조체 정렬 sort() 사용에 필요한 compare 함수
bool compare(const Node& node1, const Node& node2) {
	if (node1.y == node2.y) {
		return (node1.x < node2.x);
	}
	else {
		return (node1.y < node2.y);
	}
}

int main() {
	cin.tie(NULL);

	// 테케 개수
	int testCase;
	cin >> testCase;
	
	// 노드 배열
	Node nodeArr[101010];
	for (int i = 0; i < testCase; i++) {
		cin >> nodeArr[i].x;
		cin >> nodeArr[i].y;
	}

	// 노드 정렬
	sort(nodeArr, nodeArr + testCase, compare);
	
	// 정렬된 노드 출력
	for (int i = 0; i < testCase; i++) {
		cout << nodeArr[i].x << " " << nodeArr[i].y << "\n";
	}

	return 0;
}