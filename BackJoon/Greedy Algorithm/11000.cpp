#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int start[200000], finish[200000];

int classRoom() {
	vector<pair<int, int>> order;
	for (int i = 0; i < N; ++i) {
		order.push_back(make_pair(start[i], finish[i]));
	}
	sort(order.begin(), order.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(order[0].second);
	for (int i = 1; i < (int)order.size(); ++i) {
		if (order[i].first < pq.top()) {
			pq.push(order[i].second);

		}
		else { pq.pop(); pq.push(order[i].second); }
	}
	return pq.size();
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> start[i] >> finish[i];
	}
	cout << classRoom();
}