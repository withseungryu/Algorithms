#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;

int n;
int box[1000];
int cache[1001];

void inputBox(int k) {
	cache[k] = 1;
	for (int i = 0; i < k; ++i) {
		
		if (box[i] < box[k]) {
			cache[k] = max(cache[k],cache[i] + 1);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> box[i];

	}
	for (int i = 0; i < n; ++i) {
		inputBox(i);
	}
	sort(cache, cache+n);

	cout << cache[n-1];

}