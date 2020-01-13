#include <iostream>

using namespace std;
int tree[50];
int result[1000];
int main() {

	for (int i = 1; i < 50; i++) {
		tree[i] = (i*(i + 1)) / 2;
		
	}
	int N;
	
	int K;
	cin >> N;
	int tmpN = N;
	
	int o = 0;

	while (N--) {
		cin >> K;
		int ok = 0;
		for (int i = 1; i < 50; i++) {
			for (int j = 1; j < 50; j++) {
				for (int k = 1; k < 50; k++) {
					int tmpK = K - tree[i] - tree[j] - tree[k];
					if (tmpK == 0) { ok = 1; }

				}
			}
		}
		result[o] = ok;
		o = o + 1;
	}
	for (int i = 0; i < tmpN; i++) {
		cout << result[i] << endl;
	}
}
