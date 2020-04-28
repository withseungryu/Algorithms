#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int N;
vector<vector<int>> res;
vector<int> visited;


void dfs(int here, int cnt) {
	if (cnt != 0) {
		visited[here] = 1;
	}
	cnt++;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (visited[there] == 0) {
			dfs(there, cnt);
		}
	}
}

int main() {
	cin >> N;
	adj = vector<vector<int>>(N);

	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			if(tmp == 1)
				adj[i].push_back(j);
		}
	}


	for (int i = 0; i < N; ++i) {
		visited = vector<int>(N, 0);
		int cnt = 0;
		dfs(i, cnt);
		res.push_back(visited);
		
	}

	for (int i = 0; i < N;++i) {
		for (int j = 0; j < N; ++j) {
			cout << res[i][j] << " ";
			
		}
		cout << endl;
	}
	
}