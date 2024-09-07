#include <iostream>
using namespace std;

int main() {

	// 입력
	int file_cnt;
	cin >> file_cnt;

	int files[50];
	for (int i = 0; i < file_cnt; i++) cin >> files[i];

	int cluster;
	cin >> cluster;

	// (개별 파일 크기) > (클러스터 크기) 이면 클러스터가 하나 더 필요하다
	long long int disc_cnt = 0;
	for (int i = 0; i < file_cnt; i++) {

		if (files[i] % cluster == 0) {
			disc_cnt += files[i] / cluster;
		}
		else {
			disc_cnt += files[i] / cluster + 1;
		}

	}

	cout << disc_cnt * cluster;

	return 0;
}