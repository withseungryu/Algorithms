#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> tmp_adj;
void dfs(int x, int y, int k) {
	if (x >= 0 && y >= 0 && x < N && y < N) {
		if (tmp_adj[x][y] > k) {
			tmp_adj[x][y] = 0;
			dfs(x - 1, y, k);
			dfs(x + 1, y, k);
			dfs(x, y - 1, k);
			dfs(x, y + 1, k);
		}
	}

}

int main() {
	cin >> N;
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	int maxm = 0;


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			maxm = max(maxm, tmp);
			adj[i][j] = tmp;
		}
	}

	int ret = 0;
	for (int k =0; k < maxm; ++k) {
		int cnt = 0;
		tmp_adj = adj;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (tmp_adj[i][j] > k) {
					cnt++;
					dfs(i, j, k);
					
					
				}
			}
		}
		
		ret = max(ret, cnt);
	}

	cout << ret;

}