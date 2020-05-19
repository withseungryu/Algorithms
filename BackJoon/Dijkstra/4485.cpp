#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
int N;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

vector<vector<int>> dijkstra(int startx, int starty) {
	vector<vector<int>> dist(N, vector<int>(N, 987654321));
	dist[startx][starty] = adj[startx][starty];
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(startx, starty));
	while (!pq.empty()) {
		/*for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}*/
		int here_x = pq.top().first;
		int here_y = pq.top().second;
		int cost = dist[here_x][here_y];
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			if (there_x >= 0 && there_y >= 0 && there_x < N && there_y < N) {
				int nextDist = adj[there_x][there_y] + cost;
				if (nextDist < dist[there_x][there_y]) {
					dist[there_x][there_y] = nextDist;
					pq.push(make_pair(there_x, there_y));
				}
			}
		}

	}
	return dist;
}

int main() {
	int problem_num = 1;
	while (true) {
		cin >> N;
		if (N == 0) {
			break;
		}
		adj = vector<vector<int>>(N, vector<int>(N, 0));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int tmp;
				cin >> tmp;
				adj[i][j] = tmp;
			}
		}

		vector<vector<int>> res = dijkstra(0, 0);
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; ++j) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}*/
		
		cout << "Problem " << problem_num << ": " << res[N - 1][N - 1] << endl;
		problem_num++;
	}
}

