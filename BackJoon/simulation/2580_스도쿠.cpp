#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<pair<int, int>> visited;
bool flag = true;
int tmp_cnt;
void dfs(int cnt) {
	if (cnt == 0) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		flag = false;
	}
	else {
		if (flag) {
			int idx = tmp_cnt - cnt;
			vector<bool> check1 = vector<bool>(10, false);
			vector<bool> check2 = vector<bool>(10, false);
			vector<bool> check3 = vector<bool>(10, false);

			for (int j = 0; j < 9; ++j) {
				check1[arr[visited[idx].first][j]] = true;
				check3[arr[j][visited[idx].second]] = true;
			}

			for (int j = (visited[idx].first / 3) * 3; j < ((visited[idx].first / 3) * 3) + 3; j++) {
				for (int k = (visited[idx].second / 3) * 3; k < ((visited[idx].second / 3) * 3) + 3; k++) {
					check2[arr[j][k]] = true;
				}
			}

			for (int i = 1; i <= 9; ++i) {
				if (!check1[i] && !check2[i] && !check3[i]) {
					check1[i] = true;
					check2[i] = true;
					check3[i] = true;

					arr[visited[idx].first][visited[idx].second] = i;

					dfs(cnt - 1);

					arr[visited[idx].first][visited[idx].second] = 0;
					check1[i] = false;
					check2[i] = false;
					check3[i] = false;
				}
			}



		}
	}
	
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr = vector<vector<int>>(9, vector<int>(9, 0));
	int cnt = 0;
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				cnt++;
				visited.push_back(make_pair(i, j));
			}
		}
	}

	tmp_cnt = cnt;
	dfs(cnt);

}
