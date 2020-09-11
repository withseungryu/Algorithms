#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> cd;
	cd = vector<int>(N, 0);
	int totalSum = 0;
	int maxCd = 0;
	for (int i = 0; i < N; ++i) {
		cin >> cd[i];
		totalSum += cd[i];
		maxCd = max(maxCd, cd[i]);
	}

	long long low = maxCd; long long high = totalSum;
	long long result = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;

		long long sum = 0;
		int cnt = 0;
		bool ok = false;
		for (int i = 0; i < N; ++i) {
			sum += cd[i];
			if (sum == mid) {
				if (i < N - 1) {
					sum = 0;
					cnt++;
				}
				else {
					true;
				}
			}
			else if (sum > mid) {
				sum = cd[i];
				cnt++;
			}
		}

		if (ok) {
			result = mid;
			break;
		}

		if (cnt < M) {
			result = mid;
			high = mid - 1;
		}
		else {
			
			low = mid + 1;
		}
	}

	cout << result;
}
