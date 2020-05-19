	#include <iostream>
	#include <vector>
	#include <queue>
	#include <algorithm>

	using namespace std;

	vector<vector<pair<int, int>>> adj;
	int N, M;

	vector<int> dijkstra(int start) {
		vector<int> dist(N + 1, 987654321);
		vector<int> line(N+1);
		dist[start] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, start));
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (cost > dist[here]) continue;
			for (int i = 0; i < (int)adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int nextDist = cost + adj[here][i].second;
				if (nextDist < dist[there]) {
					dist[there] = nextDist;
					line[there] = here;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}
		return line;
	}


	int main() {
	
		cin >> N >> M;
		adj = vector<vector<pair<int, int>>>(N + 1);
		for (int i = 0; i < M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		vector<int> res = dijkstra(1);
		int cnt = 0;
		for (int i = 2; i < (int)res.size(); ++i) {
			if (res[i] != 0)
				cnt++;

		}
		cout << cnt << endl;
		for (int i = 2; i < (int)res.size(); ++i) {
			if(res[i] !=0)
				cout << i << " " << res[i]<< endl;

		}

	}