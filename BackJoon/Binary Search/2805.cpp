#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> woods;
	woods = vector<int>(N, 0);
	int maxH = 0;
	for(int i=0; i<N; ++i){
		cin >> woods[i];
		maxH = max(maxH, woods[i]);

	}

	int low = 0; int high = maxH;
	int result=0;
	while (low <= high) {
		
		int mid = (low + high) / 2;

		long long sum = 0;
		for (int i = 0; i < N; ++i) {
			if (woods[i] - mid < 0) {
				continue;
			}
			sum += woods[i] - mid;
		}


		if (sum >= M) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << result;
}
