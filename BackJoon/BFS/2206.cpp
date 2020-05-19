#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, M;

vector<vector<int>> adj;
int dist[1000][1000][2];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs(int start_x, int start_y, int wall) {

	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(start_x, start_y),wall));
	dist[start_x][start_y][wall] = 1;
	
	while (!q.empty()) {
		int here_x = q.front().first.first;
		int here_y = q.front().first.second;
		int here_wall = q.front().second;


		q.pop();
		

		if (here_x == N - 1 && here_y == M - 1) {

			return dist[here_x][here_y][here_wall];

		}
		for (int i = 0; i < 4; i++) {
		
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			
			if (there_x >= 0 && there_y >= 0 && there_x < N && there_y < M) {
			
				if (adj[there_x][there_y] == 1 && here_wall ) {
					dist[there_x][there_y][0] = dist[here_x][here_y][here_wall] + 1;
					
					q.push(make_pair(make_pair(there_x, there_y),here_wall-1));
				}
				else if (adj[there_x][there_y] == 0 && dist[there_x][there_y][here_wall] == 0) {
					dist[there_x][there_y][here_wall] = dist[here_x][here_y][here_wall] +1;
					q.push(make_pair(make_pair(there_x, there_y), here_wall));
				}
			}
			
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
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

	cout << bfs(0, 0, 1);


}