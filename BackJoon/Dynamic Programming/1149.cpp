#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int RGB[1000][3];
int cache[1001][3];
int N;
int INF = 987654321;
int findRgb() {
	for (int i = 0; i < 3;i++) {
		cache[0][i] = RGB[0][i];
	}
	for (int i = 1; i < N; i++) {
		cache[i][0] = RGB[i][0] + min(cache[i - 1][1], cache[i - 1][2]);
		cache[i][1] = RGB[i][1] + min(cache[i - 1][0], cache[i - 1][2]);
		cache[i][2] = RGB[i][2] + min(cache[i - 1][1], cache[i - 1][0]);

	}
	return 0;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	findRgb();
	int ret =INF;

		for (int j = 0; j < 3; j++) {
			ret = min(ret, cache[N-1][j]);
		}
		
	
	cout << ret;

}