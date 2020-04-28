#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int>> adj;
vector<int> discovered;
vector<pair<int, int>> res;

int counter = 0;

int bridge(int here, int parent) {
	discovered[here] = ++counter;
	int ret = discovered[here];
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (there == parent) { continue;  }
		if (discovered[there] == -1) {
		
			int subtree = bridge(there, here);
			//subtree가 갈 수 있는 선조들의 discovered 값이 부모의 discovered 값보다 클 경우 절단선이 존재한다.
			if (subtree > discovered[here]) {
				res.push_back(make_pair(min(there, here), max(there, here)));
				
			}
			ret = min(ret, subtree);
		}
		else {
			ret = min(ret, discovered[there]);
		}

	}
	return ret;
}

int main() {

	scanf("%d %d", &v, &e);
	adj = vector<vector<int>>(v + 1);
	for (int i = 0; i < e; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	discovered = vector<int>(v + 1, -1);

	for (int i = 1; i <= v; ++i) {
		if (discovered[i] == -1)
			bridge(i, 0);
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d\n", res[i].first, res[i].second);

	}

}