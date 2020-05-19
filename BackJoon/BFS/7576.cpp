#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int>> adj;
vector<vector<int>> visited;
int dir[4][2] = { {0,1},{0,-1},{1,0}, {-1,0} };
int bfs(queue<pair<int,int>> q) {
	
	int num = 0;
	int cnt = 0;
	while (!q.empty()) {
		int here_x = q.front().first;
		int here_y = q.front().second;
		
		q.pop();
		if (visited[here_x][here_y] != num) {
			num = visited[here_x][here_y];
			
			cnt++;
		}
		for (int i = 0; i < 4; ++i) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			if (there_x >= 0 && there_y >= 0 && there_x < M && there_y < N) {
				if (visited[there_x][there_y] == 0 && adj[there_x][there_y] == 0) {
					adj[there_x][there_y] = 1;
					visited[there_x][there_y] = visited[here_x][here_y]+ 1;
					q.push(make_pair(there_x, there_y));
				}
				
			}
		}
	}

	
		return cnt;

}

int main() {
	cin >> N >> M;
	queue<pair<int,int>> q;
	queue < pair<int, int>> nopre;
	adj = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				q.push(make_pair(i, j));
				adj[i][j] = 1;
			}
			else if (tmp == -1) {
				nopre.push(make_pair(i, j));
				adj[i][j] = -1;
			}
			else {
				adj[i][j] = 0;
			}

		}
	}

	visited = vector<vector<int>>(M, vector<int>(N, 0));
	while (!nopre.empty()) {
		int nox = nopre.front().first;
		int noy = nopre.front().second;
		nopre.pop();
		visited[nox][noy] = 1;
	}

	queue<pair<int,int>> tmp = q;
	
	
	int res =bfs(q);
	while (!tmp.empty()) {
		int x = tmp.front().first;
		int y = tmp.front().second;
		visited[x][y] = 1;
		tmp.pop();
	}
	int ok = true;

	for (int i = 0; i < M; ++i) {
		
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 0) {
				ok = false;
				res = -1;
				break;
			}
		}
		if (!ok) {
			break;
		}
		
	}
	cout << res;
}