#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, L;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int applecnt = 0;

queue<pair<int, int>> q;

vector<vector<int>> arr;

int snake() {
	queue<pair<int, int>> rm;
	rm.push(make_pair(0, 0));
	arr[0][0] = 1;
	int dirIdx = 0;
	int time = 0;
	int applecnt = 0;
	int x = 0, y = 0;

	while (1) {
		
		//방향 설정
		if (!q.empty() && q.front().first == time) {

				if (q.front().second == 'D') {
					dirIdx = (dirIdx + 1) % 4;
				}
				else if(q.front().second =='L') {

					dirIdx = (dirIdx - 1);
					if (dirIdx == -1) {
						dirIdx = 3;
					}
				}
			q.pop();
		}
		
		//시간 증가
		time++;

		
		x = x + dir[dirIdx][0];
		y = y + dir[dirIdx][1];

	
		//벽에 부딪힌 경우
		if (x < 0 || y<0 || x>=N || y>=N) {
			break;
		}

		//자신의 몸에 맞은 경우
		if (arr[x][y] == 1) {
			
			break;
		}

		rm.push(make_pair(x, y));

		if (arr[x][y] == 2) {
			applecnt++;
			arr[x][y] = 1;
		}
		else {
			arr[x][y] = 1;
			arr[rm.front().first][rm.front().second] = 0;
			rm.pop();
		}
	}

	return time;
}


int main() {
	cin >> N;

	
	arr = vector<vector<int>>(N, vector<int>(N, 0));

	cin >> K;
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		arr[r-1][c-1] = 2;

	}

	cin >> L;

	for (int i = 0; i < L; ++i) {
		int X; char D;
		cin >> X >> D;

		q.push(make_pair(X, D));
	}

	cout << snake();



	
}