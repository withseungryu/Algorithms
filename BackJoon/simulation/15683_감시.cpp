#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N, M;
vector<vector<int>> arr;
vector<pair<int, int>> cctv;
int total_cnt;
int answer = 64;

void move(int x, int y, int idx) {
	int dx = x + dir[idx][0]; int dy = y + dir[idx][1];

	while (dx >= 0 && dy >= 0 && dx < N && dy < M) {
		if (arr[dx][dy] == 6) {
			break;
		}
		
		if (arr[dx][dy] != 6) {
			if (arr[dx][dy] == 0) {
				arr[dx][dy] = 7;
			}
		}

		dx = dx + dir[idx][0]; dy = dy + dir[idx][1];
	}
	
}

int check() {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 0) {
				ret++;
			}
		}
	}
	return ret;
}

void dfs(int cnt) {
	if (cnt == total_cnt) {
		answer = min(answer, check());
	}
	else {
		int x = cctv[cnt].first; int y = cctv[cnt].second;
		vector<vector<int>> tmp = arr;
		
		if (arr[x][y] == 1) {
			for (int i = 0; i < 4; ++i) {
				move(x, y, i);
				dfs(cnt + 1);
				arr = tmp;
			}
		}
		else if (arr[x][y] == 2) {
			for (int i = 0; i < 2; ++i) {
				int e1 = i;
				int e2 = (i + 2)%4;
				move(x, y, e1);
				move(x, y, e2);
				dfs(cnt + 1);
				arr = tmp;
			}
		}
		else if (arr[x][y] == 3) {
			for (int i = 0; i < 4; ++i) {
				int e1 = i;
				int e2 = (i + 1) % 4;
				move(x, y, e1);
				move(x, y, e2);
				dfs(cnt + 1);
				arr = tmp;
			}
		}
		else if (arr[x][y] == 4) {
			for (int i = 0; i < 4; ++i) {
				int e1 = i-1;
				int e2 = i;
				int e3 = (i + 1) % 4;
				if (e1 == -1) {
					e1 = 3;
				}

				move(x, y, e1);
				move(x, y, e2);
				move(x, y, e3);
				dfs(cnt + 1);
				arr = tmp;				
			}
		}
		else {
			move(x, y, 0);
			move(x, y, 1);
			move(x, y, 2);
			move(x, y, 3);
			dfs(cnt + 1);
			arr = tmp;
	
		}
	}
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	arr = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp != 0 && tmp != 6) {
				total_cnt++;
				cctv.push_back(make_pair(i, j));
			}

			arr[i][j] = tmp;
		}
	}

	dfs(0);

	cout << answer;



}
