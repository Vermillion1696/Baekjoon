#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<long long int, long long int>
using namespace std;

typedef struct point {
    long long int x;
    long long int y;
} point;

typedef struct group {
    vector<pair<point, point>> v_line;
} group;

vector<group> v_group;

// CCW 함수
int CCW(pii point1, pii point2, pii point3) {
    long long int result = (point2.first - point1.first) * (point3.second - point1.second) - (point3.first - point1.first) * (point2.second - point1.second);
    if (result > 0) return 1;    // 반시계방향
    if (result < 0) return -1;   // 시계방향
    return 0;                    // 일직선
}

// 교차 판별 함수 (일직선 포함)
bool intersect(pair<point, point> a, pair<point, point> b) {
    pii point1 = { a.first.x, a.first.y };
    pii point2 = { a.second.x, a.second.y };
    pii point3 = { b.first.x, b.first.y };
    pii point4 = { b.second.x, b.second.y };

    int p1p2CCW1 = CCW(point1, point2, point3);
    int p1p2CCW2 = CCW(point1, point2, point4);
    int p3p4CCW1 = CCW(point3, point4, point1);
    int p3p4CCW2 = CCW(point3, point4, point2);

    // 한 직선 위에 있으면
    if (p1p2CCW1 == 0 && p1p2CCW2 == 0 && p3p4CCW1 == 0 && p3p4CCW2 == 0) {
        if (point1 > point2) swap(point1, point2);
        if (point3 > point4) swap(point3, point4);
        return point3 <= point2 && point1 <= point4;
    }

    return (p1p2CCW1 * p1p2CCW2 <= 0) && (p3p4CCW1 * p3p4CCW2 <= 0);
}

int main() {
    int n;
    cin >> n;

    // total_line은 입력 받은 라인들
    point tempPoint[2];
    vector<pair<point, point>> total_line;
    while (n--) {
        cin >> tempPoint[0].x >> tempPoint[0].y >> tempPoint[1].x >> tempPoint[1].y;
        total_line.push_back(make_pair(tempPoint[0], tempPoint[1]));
    }

    // total_line이 비었으면 모든 그룹 판별 완료
    while (!total_line.empty()) {
        
        // currentLine과 비교
        bool noIntersect = true;
        pair<point, point> currentLine = total_line.back();
        total_line.pop_back();

        // 새 라인 추가로 인해 다수의 그룹이 연결될 가능성 있음
        // 교차판별이 처음으로 참인 그룹의 index들을 intersectedGroups에 넣음
        vector<int> intersectedGroups;
        for (int i = 0; i < v_group.size(); i++) {
            for (int j = 0; j < v_group[i].v_line.size(); j++) {
                if (intersect(currentLine, v_group[i].v_line[j])) {
                    intersectedGroups.push_back(i);
                    break;
                }
            }
        }

        // 그룹간 병합 과정
        if (!intersectedGroups.empty()) {

            // 처음 만난 그룹에는 push_back
            int firstGroupIndex = intersectedGroups[0];
            v_group[firstGroupIndex].v_line.push_back(currentLine);

            // 다음 그룹부터는 index에 맞게 추가
            for (int k = 1; k < intersectedGroups.size(); k++) {
                int groupIndex = intersectedGroups[k];
                v_group[firstGroupIndex].v_line.insert(v_group[firstGroupIndex].v_line.end(), v_group[groupIndex].v_line.begin(), v_group[groupIndex].v_line.end());
                v_group.erase(v_group.begin() + groupIndex);

                // 그룹 사이즈가 변했으므로 인덱스 조정
                for (int& idx : intersectedGroups) {
                    if (idx > groupIndex) {
                        idx--;
                    }
                }
            }
            noIntersect = false;
        }

        // 접점이 없다면 새 그룹을 만들고 currentLine을 첫 원소로
        if (noIntersect) {
            group tempGroup;
            tempGroup.v_line.push_back(currentLine);
            v_group.push_back(tempGroup);
        }
    }

    // 각 그룹별 line의 개수중 max를 찾기
    int maxLineInGroup = 0;
    for (int i = 0; i < v_group.size(); i++) {
        if (v_group[i].v_line.size() > maxLineInGroup) {
            maxLineInGroup = v_group[i].v_line.size();
        }
    }

    // 출력
    cout << v_group.size() << "\n" << maxLineInGroup;

    return 0;
}