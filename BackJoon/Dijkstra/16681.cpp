#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000000000000
using namespace std;

int N, M, D, E;
vector<int> h;
vector < vector<pair<int, long long>>> adj;

vector<long long> startToGoal(int start) {
	
	vector<long long> dist(N+1, INF);
	dist[start] = 0;
	
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int here = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < (int)adj[here].size(); ++i) {
		
			int there = adj[here][i].first;
			long long nextDist = cost + adj[here][i].second;
			if (h[there-1] > h[here-1] && dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;

}



int main() {
	cin >> N >> M >> D >> E;
	
	adj = vector<vector<pair<int, long long>> > (N + 1);
	long long maxh = -INF;


	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		
		h.push_back(tmp);
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	vector<long long> resTo = startToGoal(1);
	vector<long long> resFrom = startToGoal(N);
	for (int i = 2; i < N; ++i) {

		long long d1 = resTo[i];
		long long d2 = resFrom[i];
		
		if (d1 != INF && d2 != INF) {
			
			long long d3 = D * (d1 + d2);
			long long h1 = h[i - 1] * E;
			long long ret = (h1 - d3);
			maxh = max(maxh, ret);
		}
	}
		
	
	if (maxh == -INF) {
		cout << "Impossible";
	}
	else {
		cout << maxh;
	}

}