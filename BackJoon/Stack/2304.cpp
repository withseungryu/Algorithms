#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int N;
int h[1001];
//int L[1000];
//int H[1000];
//
//
//int factory() {
//	vector<pair<int, int>> pq;
//	for (int i = 0; i < N; ++i) {
//		pq.push_back(make_pair(L[i], H[i]));
//	}
//	sort(pq.begin(), pq.end());
//	/*for (int i = 0; i < N; ++i) {
//		cout << pq[i].first << endl;
//	}*/
//
//	int sum = 0;
//	stack<int> st;
//	
//	st.push(0);
//	int tmp = 0;
//	int tmp2 = 0;
//	for (int i = 0; i < N; ++i) {
//		for (int j = i + 1; j < N; ++j) {
//			if (st.empty() || st.top() != i) {
//			
//				break;
//			}
//			else {
//				if (pq[i].second >= pq[j].second) {
//					
//				
//					if (tmp <= pq[j].second) {
//						tmp = pq[j].second;
//						tmp2 = j;
//					}
//					if (j == N - 1) {
//						
//						sum += pq[i].second;
//					
//						st.pop();
//						st.push(tmp2);
//						sum += (pq[tmp2].first - pq[i].first - 1)*pq[tmp2].second;
//					
//						break;
//					}
//					continue;
//				}
//				else if (pq[i].second < pq[j].second) {
//					
//					sum += (pq[j].first - pq[i].first)*pq[i].second;
//					
//					st.pop();
//					st.push(j);
//				}
//			}
//
//		}
//	}
//	sum += pq[N - 1].second;
//	return sum;
//
//}

int main() {
	cin >> N;
	int longest=0, start=1001, end=0;
	int tmpLong = 0;
	int sum = 0;
	stack<int> st;
	for (int i = 0; i < N; ++i) {
		int pos; int width;
		cin >> pos >> width;
		h[pos] = width;
		if (longest < width) { longest = width; tmpLong = pos; }
		if (start > pos) { start = pos; }
		if (end < pos) { end = pos; }

	}
	st.push(h[start]);
	for (int i = start; i < tmpLong; ++i) {
		if (h[i]) {
			if (h[i] > st.top()) { st.push(h[i]); }
		}
		sum += st.top();

	}
	st.push(h[end]);
	for (int i = end; i > tmpLong; --i) {
		if (h[i]) {
			if (h[i] > st.top()) { st.push(h[i]); }
		}
		sum += st.top();

	}
	sum += longest;
	cout << sum;
}