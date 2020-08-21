#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> arr;
int R, C;
vector<bool> visited;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int max_Num = 0;

void backtrack(int x, int y, int cnt) {

	max_Num = max(cnt, max_Num);


	for (int i = 0; i < 4; ++i) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];

		if (dx >= 0 && dy >= 0 && dx < R && dy < C) {
			if (!visited[arr[dx][dy] - 65]) {

				visited[arr[dx][dy] - 65] = true;
				backtrack(dx, dy, cnt + 1);
				visited[arr[dx][dy] - 65] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;

	arr = vector<vector<char>>(R, vector<char>(C, 0));
	visited = vector<bool>(26, false);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> arr[i][j];
		}
	}
	visited[arr[0][0] - 65] = true;
	backtrack(0, 0, 1);
	cout << max_Num << endl;
	


}
