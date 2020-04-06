#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> a;



//vector<int> partialSum(vector<int> a) {
//	vector<int> ret(a.size());
//
//
//	ret[0] = a[0];
//
//	for (int i = 1; i < a.size(); i++) {
//		ret[i] = ret[i - 1] + a[i];
//
//	}
//
//	return ret;
//}
//
//int rangeSum(vector<int> pSum, int a, int b) {
//	if (a == 0) return pSum[b];
//	return pSum[b] - pSum[a - 1];
//}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}

	int low = 0;
	int high = 0;
	int sum = a[0];
	int result = 987654321;

	while (low <= high && high < N) {
		if (sum < M) {
			sum += a[++high];
		}
		else if (sum == M) {
			result = min(result, (high - low + 1));
			sum += a[++high];
		}
		else if (sum > M) {
			result = min(result, (high - low + 1));
			sum -= a[low++];
		}

	}
	if (result == 987654321)
		cout << 0 << endl;
	else cout << result << endl;
	

}