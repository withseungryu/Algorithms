#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int N;
int L[20];
int J[20];

int hello(int firstIdx, int sum, int happy, int max);
int main() {
	int max = 0;
	int res = 0;
	int happy = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> J[i];
	}
	int tmpM = 0;
	for (int i = 0; i < N; i++) {
		int sum = 100;
	
		res = std::max(res, hello(i, sum, happy, max));
	
	}
	cout << res;

}

int hello(int firstIdx, int sum, int happy, int max) {
	int res;
	sum = sum - L[firstIdx];
	if (sum <= 0) {
		return 0;
	}
	happy = happy + J[firstIdx];	
	if (max < happy) {
		max = happy;
	}
	for (int i = firstIdx +1; i < N; i++) {
		max = std::max(max, hello(i, sum, happy, max));
	}
	return max;
}
