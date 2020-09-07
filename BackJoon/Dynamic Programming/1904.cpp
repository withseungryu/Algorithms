#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dp;
	dp = vector<int>(N + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N];

	

}
