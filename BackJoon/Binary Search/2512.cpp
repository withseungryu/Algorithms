#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> money;
	
	money = vector<int>(N, 0);

	int maxBudget = 0;
	for(int i=0; i<N; ++i){
		cin >> money[i];
		maxBudget = max(money[i], maxBudget);
	}
	int M;
	cin >> M;
	int low = 0; int high = maxBudget;
	int result;
	while (low <= high) {
		int mid = (low + high) / 2;

		long long sum = 0;
		for (int i = 0; i < N; ++i) {
			if (money[i] < mid) {
				sum += money[i];
			}
			else {
				sum += mid;
			}
		}

		if (sum <= M ) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	cout << result;

}
