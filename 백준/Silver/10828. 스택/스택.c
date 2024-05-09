#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	// 구조체 노드 선언
	typedef struct {
		int data;
		struct Node* next;
	} Node;

	// 연결 리스트 헤드, 테일
	Node* head = NULL;
	Node* tail = NULL;

	int n;
	scanf("%d", &n);
	char str[10];

	// n번 명령어 입력
	for (int i = 0; i < n; i++) {
		scanf("%s", str);

		// push 일 때
		if (strcmp(str, "push") == 0) {
			Node* newnode = (Node*)malloc(sizeof(Node));

			// newnode(임시노드)에 데이터 저장
			scanf("%d", &newnode->data);
			newnode->next = NULL;

			// 첫 노드일 때 head = newnode
			if (head == NULL) {
				head = newnode;
			}
			else { // 아니면 tail 다음 주소에 newnode
				tail->next = newnode;
			} // 그리고 tail = newnode
			tail = newnode;
		} // pop 인 경우
		else if (strcmp(str, "pop") == 0) {

			// head == NULL (들어있는 데이터가 없다)
			if (head == NULL) {
				printf("-1\n");
			}
			else {

				Node* cur = head;
				Node* cur_prev = NULL;
				// cur 노드 포인터 선언 후 cur = head

				while (cur->next != NULL) {
					cur_prev = cur;
					cur = cur->next;
				}

				printf("%d\n", cur->data);

				// 데이터가 1개 이상인 경우
				if (cur_prev != NULL) {
					cur_prev->next = NULL;
					tail = cur_prev;
				} // 데이터가 1개인 경우
				else {
					head = NULL;
					tail = NULL;
				}
				free(cur);
			}
		} // size 인 경우
		else if (strcmp(str, "size") == 0) {
			Node* cur = NULL;
			cur = head;
			int dataCNT = 0;

			// cur가 head부터 tail까지 돌면서 개수 카운트
			while (cur != NULL) {
				dataCNT++;
				cur = cur->next;
			}

			printf("%d\n", dataCNT);
		} // empty 인 경우
		else if (strcmp(str, "empty") == 0) {
			Node* cur = NULL;
			cur = head;
			int dataCNT = 0;

			// 위쪽과 똑같음
			while (cur != NULL) {
				dataCNT++;
				cur = cur->next;
			}

			// 비어있으면 1, 아니면 0
			if (dataCNT == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		} // top 인 경우 (tail->data 출력) 
		else if (strcmp(str, "top") == 0) {
			if (head == NULL) {
				printf("-1\n");
			}
			else {
				printf("%d\n", tail->data);
			}
		}
	}

	return 0;
}