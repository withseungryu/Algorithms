#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<int> weight;
vector<vector<int>> dp;
vector<bool> visited;
int N;

vector<int> res1;
vector<int> res2;

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

int getTree(int number, bool inv, int wh) {
	int &ret = dp[number][inv];
	if (ret != -1) {
		return ret;
	}


	if (inv) {

		ret = weight[number];
		for (int i = 0; i < arr2[number].size(); ++i) {
			int there = arr2[number][i];
			ret += getTree(there, false, wh);
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < arr2[number].size(); ++i) {
			int there = arr2[number][i];
			int ret1 = getTree(there, true, wh);
			int ret2 = getTree(there, false, wh);
			if (ret1 >= ret2) {
				ret += ret1;
			}
			else {
				ret += ret2;
			}
			
		}
	}

	return ret;

}

vector<bool> prevA;
void dfs(int start, int prev) {
	if (dp[start][true] > dp[start][false] && prevA[prev] == false) {
		res1.push_back(start+1);
		prevA[start] = true;
	}

	for (int i = 0; i < arr2[start].size(); ++i) {
		int there = arr2[start][i];
		if (there != prev) {
			dfs(there, start);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int w;
		cin >> w;
		weight.push_back(w);
	}

	arr = vector<vector<int>>(N);
	arr2 = vector<vector<int>>(N);
	dp = vector<vector<int>>(N, vector<int>(2, -1));

	visited = vector<bool>(N, false);

	
	int a, b;
	while (!cin.eof()) {
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);

	}
	
	visited[0] = true;
	setTree(0);

	prevA = vector<bool>(N, false);
	bool ok = false;

	int answer1 = getTree(0, true, 1);
	int answer2 = getTree(0, false, 2);

	if (answer1 >= answer2) {
		ok = true;
	}
	else {
		ok = false;
	}

	if (answer1 == 0 && answer2 == 0) {
		cout << 0 << endl;
		
	}
	else {
		if (ok) {
																																																																																																																																																																																																																																																																	cout << answer1 << endl;
																																																																																																																																																																																																																																																																}
		else {

			cout << answer2 << endl;
		}
	}

	dfs(0, 0);
	sort(res1.begin(), res1.end());
	for (int i = 0; i < res1.size(); ++i) {
		cout << res1[i] << " ";
	}


}
