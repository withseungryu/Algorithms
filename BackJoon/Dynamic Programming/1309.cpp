#include <iostream>

using namespace std;

int n;
int cache[1000001][3];
int zoo() {
	for (int i = 2; i <= n; i++) {
		cache[i][0] = (cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2])%9901;
		cache[i][1] = (cache[i - 1][0] + cache[i - 1][2])%9901;
		cache[i][2] = (cache[i - 1][0] + cache[i - 1][1])%9901;
	}
	return cache[n][0] + cache[n][1] + cache[n][2];
}

int main() {
	cin >> n;
	cache[1][0] = 1;
	cache[1][1] = 1;
	cache[1][2] = 1;

	cout << zoo();
	
}