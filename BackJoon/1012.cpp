#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int ground[50][50] = { 0 };
int N, M, K;
int cnt = 0;
int groundN(int x, int y) {
	if (x >= N || y >= M || x<0 || y<0) {
		return 0;
	}
	if (ground[x][y] == 1) {
		ground[x][y] = 0;

	}
	
	else if (ground[x][y] == 0) {
		return 0;
	}
	groundN(x + 1, y);
	groundN(x, y + 1);
	groundN(x - 1, y);
	groundN(x, y - 1);

	return 0;
}
void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			ground[i][j] = 0;
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	vector<int> result;
	while (tc--) {
		init();
		int res = 0;
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			ground[X][Y] = 1;
			
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] == 1) {
					res++;
					groundN(i, j);
				}
			}
		}
		
		result.push_back(res);

	}
	
	for (int i = 0; i < (int)result.size() ; i++) {
		if (i < ((int)result.size() - 1)) {
			cout << result[i] << endl;
		}
		else { cout << result[i]; }
	}
}

