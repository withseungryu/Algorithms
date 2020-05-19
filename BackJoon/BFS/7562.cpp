#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int adj[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };

vector<vector<int>> bfs(vector<vector<int>> dist, int startx, int starty) {
	queue<pair<int,int>> q;
	dist[startx][starty] = 0;
	q.push(make_pair(startx, starty));
	while (!q.empty()) {
		int here_x = q.front().first;
		int here_y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			
			int there_x = here_x + adj[i][0];
			int there_y = here_y + adj[i][1];
			if (there_x >= 0 && there_y >= 0 && there_x < dist.size() && there_y < dist.size()) {
				if (dist[there_x][there_y] == -1) {
					q.push(make_pair(there_x, there_y));
					dist[there_x][there_y] = dist[here_x][here_y] + 1;

				}
			}
		}
	}
	return dist;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<vector<int>> dist;
		
		int I;
		cin >> I;
		dist = vector<vector<int>>(I, vector<int>(I, -1));
		int st_x, st_y;
		cin >> st_x >> st_y;
		int end_x, end_y;
		cin >> end_x >> end_y;
		vector<vector<int>> res = bfs(dist, st_x, st_y);
		/*for (int i = 0; i <res.size(); i++) {
			for (int j = 0; j < res.size(); j++) {
				cout << res[i][j] << " ";

			}
			cout << endl;
		}*/
		cout << res[end_x][end_y] << endl;
	}
	
}