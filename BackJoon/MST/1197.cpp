#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 100001; //문제마다 다르다.
const int INF = 987654321;

int V; //정점의 개수

vector<pair<int, int>> adj[MAX_V]; // 그래프의 인접 리스트

int prim(vector<pair<int, int>> selected) {
	selected.clear();

	vector<bool> added(V, false);//해당 정점이 트리에 포함되어 있는지

	vector<int> minWeight(V, INF), parent(V, -1); 

	int ret = 0;

	minWeight[0] = parent[0] = 0; //0번 정점을 시작점으로, 항상 트리에 가장 먼저 추가

	for (int iter = 0; iter < V; ++iter) {
		int u = -1;
		for (int v = 0; v < V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;

		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;

		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	V = N;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back(make_pair(b-1, c));
	}

	vector<pair<int, int>> selected;

	int res = prim(selected);
	cout << res;

}
