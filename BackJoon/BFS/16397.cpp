#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, T, G;
vector<int> dist;

int bfs() {
	queue<int> q;
	dist[N] = 1;
	q.push(N);
	while (!q.empty()) {
	
		int here = q.front();
		q.pop();
	
		if(dist[here] == T+2){
			break;
		}
		if (here == G) {
			return dist[here] -1;
		}
		
	
		// button A
		int there_A = here + 1;
		if (there_A >= 0 && there_A < 100000 && dist[there_A] == 0) {
			dist[there_A] = dist[here] + 1;
			q.push(there_A);
		}
		int tmp_B = here * 2;
		
		if (tmp_B < 100000) {
			int there_B;
			int x = 0;
			while (true) {
				
				
				if ((int)(tmp_B / pow(10, x)) < 10) {
					there_B = tmp_B - pow(10, x);
					break;
				}
				x++;
			}
			
			if (there_B >= 0 && dist[there_B] ==0) {
				dist[there_B] = dist[here] + 1;
				q.push(there_B);
			}
			
		}
	}
	return -1;
}

int main() {
	cin >> N >> T >> G;
	dist = vector<int>(100000, 0);
	int ret = bfs();
	if (ret != -1) {
		cout << ret;
	}
	else {
		cout << "ANG";
	}

}