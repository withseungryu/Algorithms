#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dist;
int N, K;

int bfs() {
	int ret = -1;
	queue<int> q;
	dist = vector<int>(100001, 0);
	dist[N] = 1;
	q.push(N);
	while (!q.empty()) {
		int here = q.front();
		if (here == K) {
			return dist[here];
		}
		q.pop();
		int th_one = here - 1;
		if (th_one >= 0 && th_one <= 100000 && dist[th_one] == 0) {
			dist[th_one] = dist[here] + 1;
			q.push(th_one);
		}
		int th_two = here + 1;
		if (th_two >= 0 && th_two <= 100000 && dist[th_two] == 0) {
			dist[th_two] = dist[here] + 1;
			q.push(th_two);
		}
		int th_three = here * 2;
		if (th_three >= 0 && th_three <= 100000 && dist[th_three] == 0) {
			dist[th_three] = dist[here] + 1;
			q.push(th_three);
		}

	}
	return ret;
}

int main() {
	cin >> N >> K;
	
	int ret = bfs();
	cout << ret-1;
}