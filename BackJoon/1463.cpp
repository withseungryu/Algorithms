#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cache[1000001] = { 0, };
int N;
void Forone(int x) {
	cache[1] = 0;
	
	for (int i = 2; i <= x; i++) {
		cache[i] = cache[i - 1] + 1;
		if (i % 2 == 0) {
			cache[i] = min(cache[i], cache[i / 2] + 1);

		}
		if (i % 3 == 0) {
			cache[i] = min(cache[i], cache[i / 3] + 1);
		}
	}
	return;

	

}
int main() {
	cin >> N;
	Forone(N);
	cout << cache[N] << endl;
	return 0;
}