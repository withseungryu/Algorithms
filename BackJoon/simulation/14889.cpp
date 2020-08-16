#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr;
vector<bool> visited;

int answer = 987654321;
void dfs(int x, int len) {
	
	if (len == N / 2) {
		vector<int> first;
		vector<int> second;
		for (int i = 1; i <= N; ++i) {
			if (visited[i]) {
				first.push_back(i);
			}
			else {																						
				second.push_back(i);
			}
		}

		int num_first = 0;
		for (int i = 0; i < (N / 2) - 1; ++i) {
			for (int j = i + 1; j < N / 2; ++j) {
				num_first += arr[first[i]-1][first[j]-1] + arr[first[j]-1][first[i]-1];
			}
		}

		int num_second = 0;
		for (int i = 0; i < (N / 2) - 1; ++i) {
			for (int j = i + 1; j < N / 2; ++j) {
				num_second += arr[second[i]-1][second[j]-1] + arr[second[j]-1][second[i]-1];
			}
		}

		int total = abs(num_first - num_second);

		answer = min(total, answer);
	}
	else {
		for (int i = x+1; i <= N; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i, len + 1);
			}
		}
	}

	visited[x] = false;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	visited = vector<bool>(N+1, false);

	dfs(0, 0);

	cout << answer;
}
