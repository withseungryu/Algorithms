#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			dfs(there);
		}
	}

}

int main() {
	cin >> N >> M;
	adj = vector<vector<int>>(N+1);
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}
