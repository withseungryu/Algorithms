#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

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
				if (arr[len - 1] > i) {
					continue;
				}
			}
			arr[len] = i;
			backtrack(len + 1);

		}
	}



}

int main() {


	scanf("%d %d", &N, &M);

	arr = vector<int>(N + 1, 0);
	backtrack(0);





}
