#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, L;
int hole[1001];
int tmp[1001];

int protect() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (tmp[i] == 0) { continue; }
		for (int j = i + 1; j <= N; ++j) {
	
			if (j == N) { cnt++; break; }
			if ((hole[j] - hole[i]+1) <= L) {
				tmp[j] = 0;
			
				continue;
			}
			if (j == i + 1) { cnt++; break; }
			
			cnt++; break;

		}
	}
	return cnt;
}

int main() {
	cin >> N >> L;
	memset(tmp, -1, sizeof(tmp));
	
;	for (int i = 0; i < N; ++i) {
		cin >> hole[i];
	}
	sort(hole, hole + N);

	cout << protect();

}