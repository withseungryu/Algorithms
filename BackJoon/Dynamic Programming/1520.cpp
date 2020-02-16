#include <iostream>
#include <vector>
#include <math.h>
#include <memory.h>

using namespace std;

int map[500][500];
int cache[501][501];

int M, N;
int dir[4][2] = { {0,-1}, {-1,0}, {1,0}, {0,1} };
int sleeper(int x, int y) {
	if (x==0 && y==0) {
		return 1;
	}
	int& ret = cache[x][y];
	if (ret != -1) return ret;

	cache[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		if (map[x + (dir[i][0])][y + (dir[i][1])] > map[x][y] ) {
			if (x + (dir[i][0]) >= 0 && y + (dir[i][1]) >=  0 && x + (dir[i][0]) < M && y + (dir[i][1]) < N) {
	
				
				
				ret += sleeper(x + (dir[i][0]), y + (dir[i][1]));
				
				/*if (x + dir[i][0] == 2 && y + dir[i][1]==3) {
					cout << x << " : " << y << " " << endl;
				}*/
			}
			
		}
	}
	return cache[x][y];

}
int main() {
	cin >> M >> N;
	memset(cache, -1, sizeof(cache));
	cache[0][0] = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << sleeper(M-1, N-1);
	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << cache[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	
}