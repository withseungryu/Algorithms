#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int L, R, C;
vector<vector<vector<int>>> adj;
vector<vector<vector<int>>> dist;
int dir[6][3] = { {1,0,0},{-1,0,0} ,{0,1,0} ,{0,-1,0} ,{0,0,1} ,{0,0,-1} };

void bfs(int start_x, int start_y, int start_z) {
	dist = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C, -1)));
	dist[start_x][start_y][start_z] = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(start_x, make_pair(start_y, start_z)));
	while (!q.empty()) {
		int here_x = q.front().first;
		int here_y = q.front().second.first;
		int here_z = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];
			int there_z = here_z + dir[i][2];

			if (there_x >= 0 && there_y >= 0 && there_z >= 0 && there_x < L && there_y < R && there_z < C &&
				dist[there_x][there_y][there_z] == -1 && adj[there_x][there_y][there_z] == '.') {
				q.push(make_pair(there_x, make_pair(there_y, there_z)));
				dist[there_x][there_y][there_z] = dist[here_x][here_y][here_z] + 1;

			}
		}

	}

}



int main() {

	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		int start_x, start_y, start_z, end_x, end_y, end_z;
		adj = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C, '#')));
		for (int i = 0; i < L; i++) {

			for (int j = 0; j < R; ++j) {
				string str;
				cin >> str;

				if (str == "") {
					break;
				}
				for (int k = 0; k < C; ++k) {
					if (str[k] == '.') {
						adj[i][j][k] = '.';
					}
					else if (str[k] == 'S') {
						adj[i][j][k] = '.';
						start_x = i;
						start_y = j;
						start_z = k;
					}
					else if (str[k] == 'E') {
						adj[i][j][k] = '.';
						end_x = i;
						end_y = j;
						end_z = k;
					}
				}
			}
		}
		//제대로 행렬에 들어갔는지 확인 코드
		//for (int i = 0; i < L; i++) {
		//	for (int j = 0; j < R; ++j) {
		//		for (int k = 0; k < C; ++k) {
		//			cout << (char)adj[i][j][k];
		//		}
		//		cout << endl;
		//	}
		//	cout << endl;
		//}
		bfs(start_x, start_y, start_z);
		if (dist[end_x][end_y][end_z] == -1) {
			cout << "Trapped!" << endl;
		}else
			cout << "Escaped in " << dist[end_x][end_y][end_z] << " minute(s)." << endl;

	}
}