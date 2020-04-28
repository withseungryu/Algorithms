#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
vector<vector<int>> matrix;
int total = 0;
vector<int> res;
int cnt;
void searchBfs(int x, int y) {
	
	if (x < M && y < N && x >= 0 && y >= 0) {
		if (matrix[x][y] == 0) {
			cnt++;
			matrix[x][y] = 1;
			searchBfs(x + 1, y);
			searchBfs(x - 1, y);
			searchBfs(x, y+1);
			searchBfs(x, y-1);
		}
		else {
			return;
		}
	}
	
}

int main() {
	cin >> N >> M >> K;
	matrix = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < K; ++i) {
		int leftx, lefty, rightx, righty;
		cin >> leftx >> lefty >> rightx >> righty;
		for (int k = leftx; k < rightx; ++k) {
			for (int j = lefty; j < righty; ++j) {

				matrix[k][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matrix[i][j] == 0) {
				total++;
				cnt = 0;
				searchBfs(i, j);
				res.push_back(cnt);
			}
		}
	}
	cout << total << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); ++i) {
		cout << res[i] << " ";
	}

}