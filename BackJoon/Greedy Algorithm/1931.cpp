#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int start[100000];
int finish[100000];

int conference(){
	vector < pair<int, int> >order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(finish[i], start[i]));
	}
	sort(order.begin(), order.end());

	int earliest = 0, selected = 0;
	for (int i = 0; i < (int)order.size(); i++) {
		int meetingStart = order[i].second;
		int meetingEnd = order[i].first;
		if (earliest <= meetingStart) {
			earliest = meetingEnd;
			++selected;
		}
	}
	return selected;

}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> start[i] >> finish[i];
	}
	cout << conference();

}

