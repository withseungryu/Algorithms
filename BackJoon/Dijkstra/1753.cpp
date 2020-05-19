#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
int u, v, w;
vector<vector<pair<int, int>>> adj;
int INF = 987654321;

vector<int> dijkstra(int start) {
	vector<int> dist(V+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			//원래의 dist값과 큐를 이용해 구해진 nextDist값을 비교해 nextDist값이 더 적으면 대체.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cin >> V >> E;
	cin >> K;
	adj = vector < vector<pair<int, int>>>(V + 1);
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	vector<int> res = dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (res[i] != 987654321) {
			cout << res[i] << endl;
		}
		else {
			cout << "INF" << endl;
		}
	}
	

}
