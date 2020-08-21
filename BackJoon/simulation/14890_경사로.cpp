#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, L;
vector<vector<int>> arr;
int cnt = 0;
void bfs1(int x, int y) {
	queue<pair<int,int>> q;
	q.push(make_pair(y,1));

	while (!q.empty()) {
		int here_y = q.front().first;
		int way = q.front().second;
		q.pop();

		if (here_y == N - 1) {
			cnt++;
			return;
		}
		if (arr[x][here_y] == arr[x][here_y + 1]) {

			int there_y = here_y + 1;

			q.push(make_pair(there_y,1));

		}

		if (way != 3 && here_y + L - 1 < N - 1) {
			bool ok = false;
			for (int i = 1; i < L; ++i) {

				if (arr[x][here_y] == arr[x][here_y + i]) {
					ok = true;
				}
				else {
					ok = false;
					break;
				}
			}
			if (L == 1) {
				ok = true;
			}
			if (ok &&arr[x][here_y + L] - arr[x][here_y] == 1) {
		
				q.push(make_pair(here_y + L,2));
			}
		}

		if (here_y + L < N  && arr[x][here_y] - arr[x][here_y + L] == 1) {
			bool ok = false;

			for (int i = 1; i <= L; ++i) {
				if (arr[x][here_y] - 1 == arr[x][here_y + i]) {
					ok = true;
				}
				else {
					ok = false;
					break;
				}
			}
			if (L == 1) {
				ok = true;
			}
			if (ok) {

				q.push(make_pair(here_y + L,3));
			}

		}

	}
}

void bfs2(int x, int y) {
	queue<pair<int,int>> q;
	q.push(make_pair(x,1));

	while (!q.empty()) {
		int here_x = q.front().first;
		int way = q.front().second;
		q.pop();

		if (here_x == N - 1) {
		
			cnt++;
			return;
		}
		if (arr[here_x][y] == arr[here_x + 1][y]) {

			int there_x = here_x + 1;

			q.push(make_pair(there_x,1));
		}

		if (way != 3 && here_x + L - 1 < N - 1) {
			bool ok = false;
			for (int i = 1; i < L; ++i) {

				if (arr[here_x][y] == arr[here_x + i][y]) {
					ok = true;
				}
				else {
					ok = false;
					break;
				}
			}
			if (L == 1) {
				ok = true;
			}
			if (ok && arr[here_x + L][y] - arr[here_x][y] == 1) {
		
				q.push(make_pair(here_x + L,2));
			}
		}


		if (here_x + L < N  && arr[here_x][y] - arr[here_x + L][y] == 1) {
			bool ok = false;

			for (int i = 1; i <= L; ++i) {
				if (arr[here_x][y] - 1 == arr[here_x + i][y]) {
					ok = true;
				}
				else {
					ok = false;
					break;
				}
			}
			if (L == 1) {
				ok = true;
			}
			if (ok) {
			
				q.push(make_pair(here_x + L,3));
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;

	arr = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		bfs1(i, 0);
		bfs2(0, i);
	}


	cout << cnt;

}
