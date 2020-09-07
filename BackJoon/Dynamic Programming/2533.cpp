#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> dp;
vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<bool> visited;
int N;
//dp number, early
int earlyAdapter(int number, int early) {
	int& ret = dp[number][early];

	if (ret != -1) {
		return ret;
	}

	if (early) {
		ret = 1;
		for (int i = 0; i < arr2[number].size(); i++) {
			int there = arr2[number][i];
			ret += min(earlyAdapter(there, 0), earlyAdapter(there, 1));
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < arr2[number].size(); ++i) {
			int there = arr2[number][i];
			ret += earlyAdapter(there, 1);
		}
	}
	return ret;
}

void setTree(int root) {


	for (int i = 0; i < arr[root].size(); ++i) {
		int there = arr[root][i];
		if (!visited[there]) {
			visited[there] = true;
			arr2[root].push_back(there);
			setTree(there);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	arr = vector<vector<int>>(N);
	arr2 = vector<vector<int>>(N);
	visited = vector<bool>(N);

	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a-1].push_back(b-1);
		arr[b - 1].push_back(a - 1);
	}

	visited[0] = true;
	setTree(0);

	dp = vector<vector<int>>(N, vector<int>(2, -1));

	int answer = min(earlyAdapter(0, true), earlyAdapter(0,false));

	cout << answer;

	

}
