#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;
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
			if (!visited[i]) {
				visited[i] = true;
				arr[len] = i;
				backtrack(len + 1);
				visited[i] = false;
			}
		}
	}
	
	
}

int main() {


	scanf("%d %d", &N, &M);

	visited = vector<bool>(N + 1, false);
	arr = vector<int>(N + 1, 0);
	backtrack(0);



	

}
