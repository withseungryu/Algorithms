#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> base;
//vector<bool> visited;

void backtrack(int len) {

	if (len == M) {
		for (int i = 0; i < M; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");

	}
	else {
		for (int i = 1; i <= N; ++i) {
				if (len > 0) {
					if (arr[len - 1] > base[i]) {
						continue;
					}
				}
				arr[len] = base[i];
				backtrack(len + 1);
			}
		}
}





int main() {


	scanf("%d %d", &N, &M);
	base.push_back(0);
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		base.push_back(tmp);
	}

	//visited = vector<bool>(N + 1, false);
	sort(base.begin(), base.end());
	arr = vector<int>(N + 1, 0);
	backtrack(0);





}
