#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int minNum = 4;
vector<int> answer;
int cnt = 1;
bool check() {
	bool ok = false;
	for (int i = 0; i < N; ++i) {
		int x = 0; int y = i;
		int mvx = 1; int mvy = 0;
		int dx = x + mvx; int dy = y + mvy;

		while (dx < H + 1) {
			if (arr[dx][dy] != 0) {
				if (dy + 1 < N && arr[dx][dy + 1] == arr[dx][dy]) {
					dy = dy + 1;
				}
				else if (dy - 1 >= 0 && arr[dx][dy - 1] == arr[dx][dy]) {
					dy = dy - 1;
				}
			}
			dx = dx + mvx;
		}	
		if (i == dy) {
			ok = true;
		}
		else {
			ok = false;
			break;
		}
	}
	return ok;

}

void dfs(int len,int x) {
	if (minNum > len) {
		if (check()) {
			minNum = min(minNum, len);
		}

		if (len == 3) {
			return;
		}
		else {
			vector<vector<int>> tmp = arr;
			for (int i = x; i < H; ++i) {
				for (int j = 0; j < N - 1; ++j) {
					if (!visited[i][j] && !visited[i][j + 1]) {
						visited[i][j] = true;
						visited[i][j + 1] = true;
						arr[i + 1][j] = len + 1 + M;
						arr[i + 1][j + 1] = len + 1 + M;
						dfs(len + 1, i);
						visited[i][j] = false;
						visited[i][j + 1] = false;
						arr = tmp;
					}
				}
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M >> H;

	arr = vector<vector<int>>(H + 2, vector<int>(N, 0));
	visited = vector<vector<bool>>(H, vector<bool>(N, false));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;

		arr[a][b - 1] = cnt;
		arr[a][b] = cnt;
		visited[a - 1][b - 1] = true;
		visited[a - 1][b] = true;
		cnt += 1;

	}

	dfs(0, 0);
	if (minNum < 4) { cout << minNum; }
	else { cout << -1; }


}
