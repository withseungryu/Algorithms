#include <iostream>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int stick[2][100000];
int cache[2][100000];
vector<int> res;
int sticker(int n) {
	cache[0][1] = cache[1][0] + stick[0][1];
	cache[1][1] = cache[0][0] + stick[1][1];
	for (int i = 2; i < n; i++) {
		cache[0][i] = stick[0][i] + max(cache[1][i-1] , cache[1][i-2]);
		cache[1][i] = stick[1][i] + max(cache[0][i - 1] , cache[0][i - 2]);
	}
	int ret = max(cache[0][n - 1], cache[1][n - 1]);
	return ret;
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 2;i++) {
			for (int j = 0; j < n; j++) {
				cin >> stick[i][j];
			}
		}
		cache[0][0] = stick[0][0];
		cache[1][0] = stick[1][0];
		res.push_back(sticker(n));
	
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}
