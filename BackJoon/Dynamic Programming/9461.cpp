#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int N;
vector<long long> res;
long long cache[101];
long long padovan(int N) {
	if (N == 1 || N == 2 || N == 3) { return 1; }
	long long& ret = cache[N];
	if (ret != -1) { return ret; }
	return ret = padovan(N - 2) + padovan(N - 3);
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		
		res.push_back(padovan(N));
	}
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << endl;
	}
}