#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int forone = 0;
int forzero = 0;

int cache[100000];
int n, tc;


int fibonacci(int n) {
	int& ret = cache[n];
	if (n == 0) {
		forzero++;
		return 0;
	}
	else if (n == 1) {
		forone++;
		return 1;
	}
	
	else if (ret == -1) {
		return ret = fibonacci(n - 1) + fibonacci(n - 2);
	}
	else { return ret; }
	
}

int main() {
	cin >> tc;
	
	while (tc--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		if (n == 0) {
			cout << "1" << " " << "0" << endl;
		}
		else {
			cout << fibonacci(n - 1) << " " << fibonacci(n) << endl;
		}//cout << forzero << " " << forone << endl;
		//forzero = forone = 0

	} 
	/*for (int i = 0; i < tmp; i++) {
		cout << res0.at(i) << " " << res1.at(i) << endl;
	}*/
	return 0;
	
}