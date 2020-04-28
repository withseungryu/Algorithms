#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<vector<int>> adj;
int ret = 0;
vector<int> res;
void dfs(int x, int y) {
	
	if (x >= 0 && y >= 0 && x < N && y < N) {
		if (adj[x][y] == 1) {
			adj[x][y] = 0;
			ret++;
			dfs(x - 1, y);
			dfs(x + 1, y);
			dfs(x, y - 1);
			dfs(x, y + 1);
		}
		else {
			return;
		}
	}
	return;
}

int main() {
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j) {
			if (str[j] == '1') {
				adj[i][j] = 1;
			}
		}
	}
	int cnt = 0;



	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {
			if (adj[i][j] == 1) {
				
				ret = 0;
				cnt++;
				dfs(i, j);
				res.push_back(ret);
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << cnt << endl;
	for (int i = 0; i < (int)res.size();i++) {
		cout << res[i] << endl;
	}
}