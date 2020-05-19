#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> dist;
int R, C;
int start_x = 0, start_y = 0;
int end_x = 0, end_y = 0;
vector<int> ret;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void start_Fire() {
	vector<vector<int>> tmp = adj;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmp[i][j] == '*') {
				for (int k = 0; k < 4; ++k) {
					int tmp_x = i + dir[k][0];
					int tmp_y = j + dir[k][1];
					if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < R && tmp_y < C) {
						if (adj[tmp_x][tmp_y] == '.') {
							if (tmp_x == end_x && tmp_y == end_y) {
								continue;
							}
							adj[tmp_x][tmp_y] = '*';
						}
					}
				}

			}
		}
	}
}

void bfs(int start_x, int start_y) {
	int res = -1;
	dist = vector<vector<int>>(R, vector<int>(C, -1));
	dist[start_x][start_y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	int num_Fire = 0;
	start_Fire();
	

	while (!q.empty()) {

		int here_x = q.front().first;
		int here_y = q.front().second;
		if (num_Fire != dist[here_x][here_y]) {
			start_Fire();
			num_Fire = dist[here_x][here_y];
		}
		/*for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << (char)adj[i][j];
			}
			cout << endl;
		}*/
		q.pop();

		for (int i = 0; i < 4; i++) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];

			if (there_x >= 0 && there_y >= 0 && there_x < R && there_y <C) {

				if (adj[there_x][there_y] == '.' && dist[there_x][there_y] == -1) {
					q.push(make_pair(there_x, there_y));
					dist[there_x][there_y] = dist[here_x][here_y] + 1;

				}

			}


		}


	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	
		
		adj = vector<vector<int>>(R, vector<int>(C, '.'));
		for (int i = 0; i < R; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < C; j++) {
				if (str[j] == 'X') {
					adj[i][j] = 'X';
				}
				else if (str[j] == 'D') {
					end_x = i;
					end_y = j;
					
				}
				else if (str[j] == 'S') {
					start_x = i;
					start_y = j;
			
				}
				else if (str[j] == '*') {
					adj[i][j] = '*';
				}
			}
		}


		bfs(start_x, start_y);
		if(dist[end_x][end_y] != -1)
			cout << dist[end_x][end_y];
		else {
			cout << "KAKTUS";
		}

	}

