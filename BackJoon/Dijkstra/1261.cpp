#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> adj;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int N, M;

vector<vector<int>> dijkstra(int start_x, int start_y) {
	vector<vector<int>> dist(N, vector<int>(M, 987654321));
	dist[start_x][start_y] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start_x, start_y));
	while (!pq.empty()) {

		int here_x = pq.top().first;
		int here_y = pq.top().second;
		pq.pop();
		if (dist[here_x][here_y] < adj[here_x][here_y]) continue;
		for (int i = 0; i < 4; ++i) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			if (there_x >= 0 && there_y >= 0 && there_x < N && there_y < M) {
				int nextDist = adj[there_x][there_y] + dist[here_x][here_y];
				if (dist[there_x][there_y] > nextDist) {
					dist[there_x][there_y] = nextDist;
					pq.push(make_pair(there_x, there_y));
				}
			}
		}
	}
	return dist;
}

int main(){
	cin >> M >> N;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j) {
			
			if (str[j] == '1') {
				adj[i][j] = 1;
			}
		}
	}

	vector<vector<int>> res = dijkstra(0, 0);
	cout << res[N - 1][M - 1];
}