#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> finished;
int cnt = 0;
vector<int> vice;
void dfs(int here) {
	vice.push_back(here);
	visited[here] = true;
	int there = adj[here][0];
	if (there == here) {
	
		cnt++;
	}
	else if (!visited[there]) {

		dfs(there);
	}
	else if (!finished[there]) {
		
		for (int i = there; i != here; i = adj[i][0]) {
		
			cnt++;
			
		}
		cnt++;
	}

	finished[here] = true;
}


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cnt = 0;
		adj = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			adj[i].push_back(tmp);
		}
		finished = vector<bool>(n + 1, false);
		visited = vector<bool>(n + 1, false);
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				
				dfs(i);
				vice.clear();
			}
		}
		
		cout << n-cnt << endl;
	}



}