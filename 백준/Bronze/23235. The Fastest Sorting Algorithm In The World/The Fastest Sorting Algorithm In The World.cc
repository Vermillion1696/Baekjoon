#include <iostream>
#include <vector>
using namespace std;

int main() {
	int times = 1;
	int n;
	cin >> n;

	int* arr = (int*)malloc(n * sizeof(int));
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << "Case " << times << ": Sorting... done!" << "\n";
		
		times++;
		cin >> n;
	}

	return 0;
}