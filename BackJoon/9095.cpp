#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cache[12];
int Tc, n;


void ottAdd(int x) {
	cache[0] = 1;
	for (int i = 1; i <= x; i++) {
		if (i - 1 >= 0) {
			cache[i] += cache[i - 1];
		}
		if (i - 2 >= 0) {
			cache[i] += cache[i - 2];
		}
		if (i - 3 >= 0) {
			cache[i] += cache[i - 3];
		}
	}
	return;
	

}

int main() {
	cin >> Tc;
	int tmp = Tc;
	vector<int> res;
	while (Tc--) {
		for (int j = 0; j < 12; j++) {
			cache[j] = 0;
		}

		cin >> n;
	
		ottAdd(n);
		res.push_back(cache[n]);
		
		
	}
	
	for (int i = 0; i < tmp; i++) {
		
		cout << res.at(i) << endl;
	}
	return 0;
}