#include <iostream>

using namespace std;

int n, k;
int coin[101];
int cache[10001];
int ret = 0;
int findCoin(int k) {
	cache[0] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = coin[j]; i <= k; i++) {
			cache[i] = cache[i] + cache[i - coin[j]];
		}
	}
	
	return cache[k];
	
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout << findCoin(k);
	

}