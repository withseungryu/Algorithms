#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N, M;
vector<pair<int, int>> adj[502];

vector<long long> bellmanFord(int src) {
	vector<long long> upper(N+1, 99999999);
	upper[src] = 0;
	bool updated;

	for (int iter = 1; iter <= N; ++iter) {
		updated = false;
		for (int here = 1; here <= N; ++here) {
			for (int i = 0; i < (int)adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if (upper[there] > upper[here] + cost && upper[here] != 99999999 && here!=there) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b;
		int c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector<long long> res = bellmanFord(1);
	if (res.size() == 0) {
		cout << -1;
	}
	else {
		
		for (int i = 2; i < (int)res.size(); ++i) {
			if (res[i] == 99999999) {
				cout << -1;
			}
			else cout << res[i];

			if (i != res.size() - 1) cout << endl;
		}

	
	}
	

}

