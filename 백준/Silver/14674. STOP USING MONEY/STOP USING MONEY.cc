#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 각 게임에 대한 정보 class
class game {
public:
	game(int anumber, int aprice, int arate) : number(anumber), price(aprice), rate(arate) {};
	int number;
	int price;
	int rate;
	long double rating = (static_cast<long double>(rate) / price) * 10000;
};

// sort()의 인자 compare()
int compare(game a, game b) {
	if (a.rating == b.rating) {
		if (a.price == b.price) {
			return a.number < b.number;
		}
		else {
			return a.price < b.price;
		}
	}
	else {
		return a.rating > b.rating;
	}
}

int main() {
	int list, buy, anumber, aprice, arate;
	cin >> list >> buy;
	vector<game> v;

	// 입력
	for (int i = 0; i < list; i++) {
		cin >> anumber >> aprice >> arate;
		game* ptr = new game(anumber, aprice, arate);
		v.push_back(*ptr);
	}

	// 정렬
	sort(v.begin(), v.end(), compare);

	// 디버깅 함수
	/*
	for (int i = 0; i < list; i++) {
		cout << v[i].number << " " << v[i].price << " " << v[i].rate << " " << v[i].rating << "\n";
	}
	*/

	// 정렬된 데이터의 number 출력
	for (int i = 0; i < buy; i++) {
		cout << v[i].number << "\n";
	}

	return 0;
}