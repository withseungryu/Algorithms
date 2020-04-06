#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int N, P;
int cnt = 0;
stack<int> st[7];
bool inspect(int q, int cmp) {

	stack<int> tmp = st[q];
	int size = tmp.size();

	if (!tmp.empty()) {
		
		for (int i = 0; i < size; i++) {

			if (cmp == tmp.top()) {
				return true;
			}
			else {
			
				tmp.pop();
			}
			if (tmp.empty()) {
			
				return false;
			}
		}
	}
	return false;
	
}

void runInspect(int q, int cmp) {


	int size = st[q].size();

	if (!st[q].empty()) {

		for (int i = 0; i < size; i++) {

			if (cmp == st[q].top()) {
				break;
			}
			else {

				st[q].pop(); cnt++;
			}
			if (st[q].empty()) {

				break;
			}
		}
	}


}
int main() {

	vector<pair<int, int>> pq;

	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		pq.push_back(make_pair(a1, a2));
	}

	for (int i = 0; i < N; ++i) {

		
		
		if (!st[pq[i].first].empty() && (st[pq[i].first].top() >= pq[i].second)) {
			if (inspect(pq[i].first, pq[i].second)) {
				runInspect(pq[i].first, pq[i].second);
				continue;
			}
			else{
				while (!st[pq[i].first].empty() && st[pq[i].first].top() > pq[i].second) {

				st[pq[i].first].pop(); cnt++;
				//if (st[pq[i].first].empty()) { break; }
			}}

			st[pq[i].first].push(pq[i].second); cnt++;
		}
		else if (st[pq[i].first].empty() || (st[pq[i].first].top() < pq[i].second)) {

			st[pq[i].first].push(pq[i].second); cnt++;
		}

	}

	cout << cnt;

}