#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> numbers;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		numbers.push_back(tmp);
	}

	vector<char> op;
	for (int i = 0; i < 4; ++i) {
		int tmp;
		cin >> tmp;

		for (int j = 0; j < tmp; j++) {
			if (i == 0) {
				op.push_back(0);
			}
			else if (i == 1) {
				op.push_back(1);
			}
			else if (i == 2) {
				op.push_back(2);
			}
			else if (i == 3) {
				op.push_back(3);
			}
		}
	}

	int minNum = 1000000000;
	int maxNum = -1000000000;

	do {


		int idx = 0;
		int res = numbers[idx];
		for (int i = 0; i < N - 1; ++i) {
			if (op[i] == 0) res += numbers[++idx];
			else if (op[i] == 1) res -= numbers[++idx];
			else if (op[i] == 2) res *= numbers[++idx];
			else if (op[i] == 3) { 
				if (numbers[idx] < 0) {
					res *= -1;
					res /= numbers[++idx];
					res *= -1;
				}
				else res /= numbers[++idx];
			}
		}

		minNum = min(minNum, res);
		maxNum = max(maxNum, res);


	} while (next_permutation(op.begin(), op.end()));

	cout << maxNum << endl;
	cout << minNum;
}
