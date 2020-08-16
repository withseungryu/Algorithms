#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> arr;
vector<pair<int, int>> virus;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N, M;

vector<vector<int>> select(int x1, int y1, int x2, int y2, int x3, int y3) 
{
	vector<vector<int>> tmp = arr;
	tmp[x1][y1] = 1;
	tmp[x2][y2] = 1;
	tmp[x3][y3] = 1;

	return tmp;

}

int bfs(vector<vector<int>> tmp) {
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	queue<pair<int, int>> q;



	for (int i = 0; i < virus.size(); ++i) {
		q.push(make_pair(virus[i].first, virus[i].second));
		visited[virus[i].first][virus[i].second] = true;
	}
	

	while (!q.empty()) {
		int here_x = q.front().first;
		int here_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int there_x = here_x + dir[i][0];
			int there_y = here_y + dir[i][1];

			if (there_x >= 0 && there_y >= 0 && there_x < N && there_y < M && !visited[there_x][there_y] && tmp[there_x][there_y] == 0) {
				visited[there_x][there_y] = true;
				tmp[there_x][there_y] = 2;
				q.push(make_pair(there_x, there_y));
			}
		} 
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; ++j) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	arr = vector<vector<int>>(N, vector<int>(M, 0));
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	for (int x1 = 0; x1 < N; ++x1) {
		for (int y1 = 0; y1 < M; ++y1) {

			if (arr[x1][y1] == 0) {

				for (int x2 = x1; x2 < N; ++x2) {
					for (int y2 = 0; y2 < M; ++y2) {
						if (x1 == x2) {
							if (y1 <= y2) {
								continue;
							}
						}

						if (arr[x2][y2] == 0) {

							for (int x3 = x2; x3 < N; ++x3) {
								for (int y3 = 0; y3 < M; ++y3) {

									if (x2 == x3) {
										if (y2 <= y3) {
											continue;
										}
									}

									if (arr[x3][y3] == 0) {
										
										vector<vector<int>> tmp = select(x1, y1, x2, y2, x3, y3);

										answer = max(answer, bfs(tmp));
									
									}



								}
							}
						}

					}
				}
			}
		}
	}

	cout << answer;


}
