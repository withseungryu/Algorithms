#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> rope;

int weight() {
	int maximum = 0;

	sort(rope.begin(), rope.end());
	for (int i = 0; i < N; ++i) {
		
	
			maximum = max(maximum, rope[i]*(N-i));
		
	}
	
	return maximum;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		rope.push_back(tmp);
	}
	printf("%d",weight());
}