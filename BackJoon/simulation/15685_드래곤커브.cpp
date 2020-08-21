#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0}};
vector<vector<int>> arr;
vector<vector<int>> dp;
int x, y, d, g;

void make() {
	for (int i = 0; i < 11; ++i) {
		if (i == 0) {			
		}
		else {
			dp[i] = dp[i - 1];
			for (int j = dp[i-1].size()-1; j >= 0; --j) {
				dp[i].push_back((dp[i - 1][j] + 1)%4);
			}
		}
	}
}

void dragon() {
	arr[x][y] = 1;
	int dx = x; int dy = y;
	int idx = d;
	for (int i = 0; i < dp[g].size(); ++i) {

		dx = dx + dir[(idx + dp[g][i])%4][0];
		dy = dy + dir[(idx + dp[g][i])%4][1];

		arr[dx][dy] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	arr = vector<vector<int>>(101, vector<int>(101, 0));
	dp = vector < vector<int>>(11, vector<int>(1, 0));

	make();

	for (int i = 0; i < N; ++i) {
		
		cin >> y >> x >> d >> g;
		dragon();
	}
	int answer = 0;

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			bool ok = true;
			for (int e1 = i; e1 < i + 2; ++e1) {
				for (int e2 = j; e2 < j + 2; ++e2) {
					if (arr[e1][e2] == 0) {
						ok = false;
					}
				}
			}
			if (ok) {
				answer++;
			}
		}

	}

	cout << answer;

	

	
}
