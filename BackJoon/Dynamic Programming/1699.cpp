#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	vector<int> dp;
	int M = (int)sqrt(N);
	dp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		dp[i] = i;
	}

	for (int i = 2; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (pow(i, 2) <= j) dp[j] = min(dp[j], dp[j-pow(i,2)] + 1);
		}
	}

	cout << dp[N];
}
