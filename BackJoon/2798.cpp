#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int card[100];
int ans = 0;
void blackJack(int firstIdx, int cnt, int total) {

	if (cnt == 3) {
		if (total <= M) {
			ans = std::max(ans, total);
			
		}
		return;
	}
	if (total > M || firstIdx >= N) return;

	blackJack(firstIdx + 1, cnt + 1, total + card[firstIdx]);
	blackJack(firstIdx + 1, cnt, total);
}

int main() {
	cin >> N >> M;
	int total = 0;
	int cnt = 1;
	int res = 0;
	int max = 0;
	for (int i = 0; i < N; ++i) {
		cin >> card[i];
	}
	blackJack(0, 0, 0);
	cout << ans;

}
