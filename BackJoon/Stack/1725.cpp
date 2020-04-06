#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> h;


int hisGram(int left, int right) {
	if (left == right) {
	
		return h[left];
	}
	int mid = (left + right) / 2;
	int ret = max(hisGram(left, mid), hisGram(mid + 1, right));
	//겹치는 경우
	int lo = mid; int hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	//겹치고 나서 확장을 하자
	while (left < lo || right > hi) {
		if (hi < right && (left == lo || (h[lo - 1] < h[hi + 1]))){
			++hi;
			height = min(height, h[hi]);

		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	int ret = hisGram(0, h.size()-1);
	cout << ret;


}