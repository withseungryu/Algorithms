#include <iostream>
#include <vector>

using namespace std;

int N, M;
int a[10000];

//vector<int> partialSum(vector<int> a) {
//	vector<int> ret(a.size());
//	
//	
//
//
//	ret[0] = a[0];
//	
//	for (int i = 1; i <  a.size(); i++) {
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
		cin >> a[i];
	}
	
	int cnt = 0;
	int low = 0, high = 0;
	int sum = a[0];
	while (low <= high && high < N) {
		if (sum < M) {
			sum += a[++high];
		}
		else if (sum == M) {
			cnt++;
			sum += a[++high];

		}
		else if (sum > M) {
			sum -= a[low++];
			if (low > high && low < N)

			{

				high = low;

				sum = a[low];

			}
		}
	}
	printf("%d", cnt);


}