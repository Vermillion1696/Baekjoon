#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 노드 구조체 선언
	typedef struct Node {
		int data;
		struct Node* next;
	} Node;

	// 헤드, 테일 노드 포인터 == NULL
	Node* head = NULL;
	Node* tail = NULL;

	int n, k;
	scanf("%d %d", &n, &k);


	// 선형 연결 리스트를 만들고
	for (int i = 1; i <= n; i++) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = i;
		newnode->next = NULL;

		if (head == NULL) {
			head = newnode;
		}
		else {
			tail->next = newnode;
		}
		tail = newnode;
	}

	// tail의 다음이 head로 선언해 원형 연결 리스트를 만듦
	tail->next = head;
	
	int* arr = (int*)malloc(n * sizeof(int));
	int count = 1;
	int memCNT = 0;

	// head부터 시작
	Node* cur = head;
	Node* cur_prev = tail;

	printf("<");
	while (1) {
		// 아니면 count++ 하고 포인터 옮기기
		if (count < k) {
			count++;
			cur_prev = cur;
			cur = cur->next;
		}
		else { // 맞으면 cur_prev->next = cur->next 후 cur 제거, cur 재정의 
			cur_prev->next = cur->next;

			if (memCNT != n - 1) {
				printf("%d, ", cur->data);
			}
			else {
				printf("%d", cur->data);
			}
			memCNT++;

			count = 0;
			
			if (memCNT == n) {
				printf(">");
				break;
			}
		}
	}
	
	return 0;
}