#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> dist;
int w, h;
vector<int> ret;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<pair<int, int>> fire;
void start_Fire() {
	int fire_size = fire.size();
	for (int i = 0; i < fire_size; ++i) {
		
		int here_x = fire.front().first;
		int here_y = fire.front().second;
		fire.pop();
		for (int j = 0; j < 4; ++j) {
			int there_x = here_x + dir[j][0];
			int there_y = here_y + dir[j][1];
			if (there_x >= 0 && there_y >= 0 && there_x < h && there_y < w) {
				
				if (adj[there_x][there_y] == '.') {
					fire.push(make_pair(there_x, there_y));
					adj[there_x][there_y] = '*';
				}
			}
		}
	}
}

int bfs(int start_x, int start_y) {
	int res = -1;
	dist = vector<vector<int>>(h, vector<int>(w, -1));
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
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];

			if (there_x >= 0 && there_y >= 0 && there_x < h && there_y < w) {

				if (adj[there_x][there_y] == '.' && dist[there_x][there_y] == -1) {
					q.push(make_pair(there_x, there_y));
					dist[there_x][there_y] = dist[here_x][here_y] + 1;

				}

			}
			else {

				return res = dist[here_x][here_y] + 1;
				
			}
					
		}

			
	}

	

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int tc;
	cin >> tc;
;	while (tc--) {
		cin >> w >> h;
		int start_x = 0, start_y = 0;
		adj = vector<vector<int>>(h, vector<int>(w, '.'));
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			
			for (int j = 0; j < w; j++) {
				if (str[j] == '#') {
					adj[i][j] = '#';
				}
				else if (str[j] == '*') {
					fire.push(make_pair(i, j));
					adj[i][j] = '*';
				}
				else if (str[j] == '@') {
					start_x = i;
					start_y = j;
					adj[i][j] = '.';
				}
			}
		}


		int res = bfs(start_x, start_y);
		while (!fire.empty()) {
			fire.pop();
		}
		if (res != -1) { cout << res << endl; }
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	
}