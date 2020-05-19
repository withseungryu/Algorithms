#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> adj;
int start, v;
int m;
vector<int> dist;
vector<int> parent;

void bfs2(int start) {
	dist = vector<int>(n + 1, -1);
	parent = vector<int>(n + 1, -1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			if (dist[there] == -1) {
				q.push(there);
				dist[there] = dist[here] + 1;
	
			}
		}
	}
}



int main() {
	scanf("%d", &n);
	scanf("%d %d", &start, &v);
	scanf("%d", &m);
	
	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs2(start);
	
	if (dist[v] != -1)
		printf("%d", dist[v]);

	else
		printf("%d", -1);
}