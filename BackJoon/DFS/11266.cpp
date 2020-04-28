#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter=0;
int cnt = 0;
int isCutVertexDfs(int here, bool root) {
	discovered[here] = ++counter;
	int ret = discovered[here];
	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			++children;
			int subtree = isCutVertexDfs(there, false);
			if (!root && subtree >= discovered[here]) {
			
				isCutVertex[here] = true;
			}
			ret = min(ret, subtree);
		}
		else {
			ret = min(ret, discovered[there]);
		}
	
	}if (root) {
		isCutVertex[here] = (children >= 2);

	}
	return ret;
}

int main() {
	cin >> v >> e;
	adj = vector<vector<int>>(v + 1);
	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	discovered = vector<int>(v + 1, -1);
	isCutVertex = vector<bool>(v + 1, false);
	
	for (int i = 1; i <= v; ++i) {
		if(discovered[i] == -1)
			isCutVertexDfs(i, true);
	}
	
	for (int i = 0; i < (int)isCutVertex.size(); ++i) {
		if (isCutVertex[i])
			cnt++;
	}
	cout << cnt << endl;
	
	for (int i = 0; i < (int)isCutVertex.size(); ++i) {
		if (isCutVertex[i])
			cout << i << " ";
	}

}