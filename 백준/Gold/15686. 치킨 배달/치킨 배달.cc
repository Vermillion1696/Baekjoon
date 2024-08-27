#include <iostream>
#include <vector>
#include <cmath>
#define fast_output cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
constexpr int MAX = 51;
int map[MAX][MAX];

// 집, 치킨집의 위치 저장 벡터
vector<pair<int, int>> house_v, chicken_v;

// 맵 사이즈, 남을 치킨 집 수
int map_size, chicken_left;

// 백트래킹에 쓸 것
int index_array[15];
bool is_used[15];

// 치킨 거리의 최솟값
int min_dist = 1e9;

void distance_calculate() {

	// 현재 비교군인 치킨집 위치 벡터
	// 백트래킹으로 만들어진 순열에 해당하는 치킨집 주소만 넣음
	vector<pair<int, int>> cur_chicken_v;
	for (int i = 0; i < chicken_left; i++) {
		int cur_index = index_array[i];
		cur_chicken_v.push_back(chicken_v[cur_index]);
	}

	int total = 0;
	int house_size = house_v.size();
	int cur_chicken_v_size = cur_chicken_v.size();
	
	// 각 집마다 각 치킨집과의 거리를 비교해 가장 적은 거리를 total에 더함
	for (int i = 0; i < house_size; i++) {
		int this_house_min = 1e9;

		for (int j = 0; j < cur_chicken_v_size; j++) {
			this_house_min = min(this_house_min, abs(cur_chicken_v[j].first - house_v[i].first) + abs(cur_chicken_v[j].second - house_v[i].second));
		}

		total += this_house_min;
	}

	// 나온 total이 min_dist보다 작으면 -> min_dist에 저장
	min_dist = min(min_dist, total);

	return;
}

// chicken_v.size() 에서 chicken_left 만큼 골라 만든 조합
int select_size;
void back_tracking(int k) {

	if (k == chicken_left) {
		/*
		for (int i = 0; i < chicken_left; i++) {
			cout << index_array[i] << ' ';
		}
		cout << '\n';
		*/

		// 백트래킹으로 나온 순열로 거리 계산
		distance_calculate();

		return;
	}

	for (int num = 0; num < select_size; num++) {
		if (is_used[num]) continue;
		if (k != 0 && num <= index_array[k - 1]) continue;

		index_array[k] = num;

		is_used[k] = true;
		back_tracking(k + 1);
		is_used[k] = false;
	}
	
	return;
}

int main() {
	fast_output;

	cin >> map_size >> chicken_left;

	// 입력
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) house_v.push_back({ i,j });
			if (map[i][j] == 2) chicken_v.push_back({ i,j });
		}
	}

	select_size = chicken_v.size();

	back_tracking(0);

	cout << min_dist;

	return 0;
}