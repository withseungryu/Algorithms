#include <iostream>
#include <memory.h>
using namespace std;

int n;
int cache[31];

int tiling(int n) {
	if (n == 0) { return 1; }
	else if (n < 0 || n==1) { return 0; }
	int& ret = cache[n];
	if (ret != -1) { return ret; }
	return ret = 3 * tiling(n - 2) + 2 * tiling(n - 4);
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << tiling(n);
}