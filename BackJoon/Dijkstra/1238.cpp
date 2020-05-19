#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> adj;


vector<int> dijkstra(int start) {
	vector<int> dist(M + 1, 987654321);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}

		}
	}
	return dist;
}

int main() {
	cin >> N >> M >> X;
	adj = vector<vector<pair<int, int>>>(M + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector<int> res = dijkstra(X);
	int max_num =0;

	for (int i = 1; i <= M; ++i) {
		if (res[i] != 987654321 && res[i] != 0) {
			vector<int> res_back = dijkstra(i);
			if (res_back[X] != 987654321) {
				max_num = max(max_num, res_back[X] + res[i]);
			}
		}
	}
	cout << max_num << endl;
}
