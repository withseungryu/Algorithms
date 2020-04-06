#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;

//int findmax() {
//
//	int max = 0;
//	int idx=0;
//	for (int i = 0; i < N; i++) {
//		if (max < arr[i][row[i]]) {
//			max = arr[i][row[i]];
//			idx = i;
//
//		}
//	}
//	return idx;
//}
//
//void bigger() {
//
//	for (int i = 0; i < N-1; i++) {
//		int idx;
//		idx = findmax();
//		row[idx] -= 1;
//		if (i == N - 2) {
//			res = idx;
//		}
//	}
//
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int x;

	for (int i = 0; i < N*N; i++) {
		cin >> x;
		if ((int)pq.size() < N) {
			pq.push(x);
		}
		else {
			if (pq.top() < x) {
				pq.pop();
				pq.push(x);
			}
		}
	}
	cout << pq.top();

}