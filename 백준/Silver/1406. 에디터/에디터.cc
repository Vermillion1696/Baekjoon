#include <iostream>
using namespace std;

// 구조체 노드 선언
typedef struct Node {
	char data;
	Node* prev = NULL;
	Node* next = NULL;
} Node;

// 디버깅 함수
/*
void printString(Node** tcursor, Node** tcursor_prev, Node** head, Node** tail) {
	*tcursor = *head;
	*tcursor_prev = NULL;

	cout << "현재 문자열 : ";
	while (*tcursor != NULL) {
		cout << (*tcursor)->data;
		*tcursor_prev = *tcursor;
		*tcursor = (*tcursor)->next;
	}
	cout << "\n";
}

void printCursor(Node* cursor, Node* cursor_prev) {
	cout << "커서 이전 문자 : ";
	if (cursor_prev != NULL) {
		cout << cursor_prev->data;
	}
	else {
		cout << "NULL";
	}
	cout << "\n";

	cout << "커서 다음 문자 : ";
	if (cursor != NULL) {
		cout << cursor->data;
	}
	else {
		cout << "NULL";
	}
	cout << "\n";
}
*/

int main() {
	
	// 시작 문자열 입력
	string str;
	cin >> str;

	// 노드 포인터 시작점 head, 끝점 tail, 현재점 current
	Node* head = NULL;
	Node* tail = NULL;
	Node* current = NULL;
	for (int i = 0; str[i] != NULL; i++) {
		Node* newnode = new Node;
		
		if (i == 0) {
			newnode->data = str[i];
			head = newnode;
			tail = newnode;
			current = newnode;
		}
		else {
			newnode->data = str[i];
			
			newnode->prev = current;
			current->next = newnode;
			current = current->next;

			tail = newnode;
		}
	}

	// 명령어 횟수
	int n;
	cin >> n;

	// 노드 포인터 cursor, cursor_prev
	Node* cursor = head;
	Node* cursor_prev = NULL;

	// 디버깅용 변수 tcursor, tcursor_prev
	/*
	Node* tcursor = head;
	Node* tcursor_prev = NULL;
	*/

	// cursor == head부터 cursor == NULL 일 때까지 찾아감, 이 때 cursor_prev == tail
	while (cursor != NULL) {
		cursor_prev = cursor;
		cursor = cursor->next;
	}

	while (n--) {

		// 명령어
		char c;
		cin >> c;

		// L인 경우
		if (c == 'L') {
			// 커서 현 위치가 맨 왼쪽이 아닌 경우
			if (cursor_prev != NULL) {
				// 커서 왼쪽 이동
				cursor = cursor_prev;
				cursor_prev = cursor_prev->prev;
			}
		}
		// D인 경우
		else if (c == 'D') {
			// 커서 현 위치가 맨 오른쪽이 아닌 경우
			if (cursor != NULL) {
				// 커서 오른쪽 이동
				cursor_prev = cursor;
				cursor = cursor->next;
			}
		}
		// B인 경우
		else if (c == 'B') {
			// cursor_prev를 지울 예정, 즉, 지울 게 있는 경우
			if (cursor_prev != NULL) {
				// deletingPtr은 지울 노드를 가리킴
				Node* deletingPtr = cursor_prev;

				// 지울 변수가 head면 커서를 움직이지 않아도 된다
				if (deletingPtr == head) {
					head = cursor;
					cursor->prev = NULL;
					free(deletingPtr);
					cursor_prev = NULL;
				}
				// 지울 변수가 head가 아니면, 커서를 왼쪽으로 한 칸 움직여야 한다
				else {
					cursor_prev = cursor_prev->prev;
					cursor == NULL ? cursor_prev->next = NULL : cursor_prev->next = cursor;

					if (cursor != NULL) {
						cursor->prev = cursor_prev;
					}

					if (deletingPtr == tail) {
						tail = cursor_prev;
					}

					free(deletingPtr);
				}
			}
		}
		// P인 경우
		else if (c == 'P') {
			// 입력할 문자 temp
			char temp;
			cin >> temp;

			// 추가할 노드 newnode
			Node* newnode = new Node;
			newnode->data = temp;
			cursor_prev = NULL ? newnode->prev = NULL : newnode->prev = cursor_prev;
			cursor = NULL ? newnode->next = NULL : newnode->next = cursor;
			
			// cursor_prev == NULL이면 새 노드는 head
			if (cursor_prev != NULL) {
				cursor_prev->next = newnode;
			}
			else {
				head = newnode;
			}

			// cursor == NULL이면 새 노드는 tail
			if (cursor != NULL) {
				cursor->prev = newnode;
			}
			else {
				tail = newnode;
			}

			cursor_prev = newnode;
		}
	}

	// 출력
	cursor = head;
	cursor_prev = NULL;
	while (cursor != NULL) {
		cout << cursor->data;

		cursor_prev = cursor;
		cursor = cursor->next;
	}

	return 0;
}