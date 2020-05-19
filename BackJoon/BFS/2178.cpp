#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
vector<vector<int>> adj;
vector<vector<int>> dist;

void bfs(int startx, int starty) {
	dist = vector<vector<int>>(N, vector<int>(M, -1));
	queue<pair<int, int>> q;
	dist[startx][starty] = 1;
	q.push(make_pair(startx, starty));

	while (!q.empty()) {
		
		int here_x = q.front().first;
		int here_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			if (there_x >= 0 && there_y >= 0 && there_x < N && there_y < M && dist[there_x][there_y] == -1 && adj[there_x][there_y] == 1) {
				q.push(make_pair(there_x, there_y));
				dist[there_x][there_y] = dist[here_x][here_y] + 1;

			}
		}
	}
}

int main() {
	cin >> N >> M;
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
	
	bfs(0, 0);
	cout << dist[N - 1][M - 1];

}