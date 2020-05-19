#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
int N, M;

vector<int> dijkstra(int start) {
	vector<int> dist(N + 1, 987654321);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		
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
	cin >> N;
	cin >> M;
	adj = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	int start, end;
	cin >> start >> end;
	vector<int> res = dijkstra(start);
	
	
	cout << res[end];

}