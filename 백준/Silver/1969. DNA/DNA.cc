#include <iostream>
#include <vector>
using namespace std;
char seq[4] = { 'A','C','G','T' };

int main() {
	int str_cnt, str_len;
	cin >> str_cnt >> str_len;

	// 입력
	vector<string> dna;
	string input;
	for (int i = 0; i < str_cnt; i++) {
		cin >> input;
		dna.push_back(input);
	}

	int tot = 0;
	vector<char> out_dna;
	for (int i = 0; i < str_len; i++) {
		
		// 각 column에서 알파벳 개수
		constexpr int A = 0, C = 1, G = 2, T = 3;
		int diff[4] = {};
		
		for (int j = 0; j < str_cnt; j++) {
			switch (dna[j][i]) {
			case 'A':
				diff[A]++;
				break;
			case 'C':
				diff[C]++;
				break;
			case 'G':
				diff[G]++;
				break;
			case 'T':
				diff[T]++;
				break;
			}
		}

		// 디버깅
		/*
		for (int j = 0; j < 4; j++) cout << diff[j];
		cout << endl;
		*/

		// 최대 찾기
		vector<char> max_chr;
		int max_int = -1;
		for (int j = 0; j < 4; j++) {
			if (max_int <= diff[j]) {
				if (max_int == diff[j]) max_chr.push_back(seq[j]);
				else {
					max_chr.clear();
					max_chr.push_back(seq[j]);
				}

				max_int = diff[j];
			}
		}

		// column에서 (dna 개수 - 동일 염기 개수) 가 그 column의 Hamming Distance
		// max_chr에 A, C, G, T 순으로 넣었다 -> 입력 자체가 사전순 정렬
		tot += str_cnt - max_int;
		out_dna.push_back(max_chr[0]);
	}

	for (int i = 0; i < out_dna.size(); i++) {
		cout << out_dna[i];
	}
	cout << endl << tot;
}