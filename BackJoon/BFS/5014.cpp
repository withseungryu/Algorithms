#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
vector<vector<int>> adj;
vector<int> dist;


void bfs(int start) {
	dist = vector<int>(F + 1, -1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
		
			if (dist[there] == -1) {
				q.push(there);
				dist[there] = dist[here] + 1;

			}
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	adj = vector<vector<int>>(F+1);
	int tmp[2] = { U, -(D) };
	for (int i = 1; i <= F; i++) {
		for (int j = 0; j < 2; ++j) {
			if (j == 0) {
				if (i + tmp[j] <= F) {
					adj[i].push_back(i+tmp[j]);
				}
			}
			else {
				if (i + tmp[j] > 0) {
					adj[i].push_back(i+tmp[j]);
				}
			}
		}
	}

	bfs(S);
	if (dist[G] == -1) {
		cout << "use the stairs";
	}else
	cout << dist[G];
}


int a, b;
while (true) {
	cin >> a;
	if (cin.eof() == true) {
		break;
	}
	//여기에 결과 값 입력!
}