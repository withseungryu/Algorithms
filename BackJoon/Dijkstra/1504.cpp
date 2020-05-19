#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, E;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start) {
	vector<int> dist(N + 1, 987654321);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}

		}
	}
	return dist;
}

int main() {
	cin >> N >> E;
	adj = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	int v1, v2;
	cin >> v1 >> v2;
	vector<int> ret1 = dijkstra(1);
	vector<int> ret2 = dijkstra(v1);
	vector<int> ret3 = dijkstra(v2);

	int res1, res2;
	if (ret1[v1] != 987654321 && ret2[v2] != 987654321 && ret3[N] != 987654321) {
		res1 = ret1[v1] + ret2[v2] + ret3[N];
	}
	else {
		res1 = 987654321;
	}

	if (ret1[v2] != 987654321 && ret3[v1] != 987654321 && ret2[N] != 987654321) {
		res2 = ret1[v2] + ret3[v1] + ret2[N];
	}
	else {
		res2 = 987654321;
	}

	if (res1 != 987654321 && res2 != 987654321) {
		cout << min(res1, res2);

	}
	else {
		cout << -1;
	}


}