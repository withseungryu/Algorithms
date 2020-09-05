#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;



int main() {
	cin >> N >> K;
	vector<pair<int, int>> gym;

	for (int i = 0; i < N; ++i) {
		int W, V;
		cin >> W >> V;
		gym.push_back(make_pair(W, V));
	}

	vector<vector<int>> dp;
	dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 0; i <= K; ++i) {
		if (gym[0].first <= i) dp[0][i] = gym[0].second;
	}
 
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (gym[i].first <= j) dp[i][j] = max(dp[i - 1][j], gym[i].second + dp[i - 1][j - gym[i].first]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N-1][K];
	
}
