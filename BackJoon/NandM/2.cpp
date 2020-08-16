#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;

void backtrack(int x, int len) {

	if (len == M) {
		for (int i = 1; i <= N; ++i) {
			if (visited[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else {
		for (int i = x + 1; i <= N; ++i) {
			visited[i] = true;
			backtrack(i, len + 1);
			
		}
	}

	visited[x] = false;
}

int main() {
	scanf("%d %d", &N, &M);

	visited = vector<bool>(N + 1, false);

	backtrack(0, 0);


	

}
