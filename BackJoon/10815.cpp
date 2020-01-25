#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> card;
vector<int> ownCard;
vector<int> result;
int N, M;
int findCard(int left, int right, int idx) {
	if (left == right) { return 0; }
	int mid = ((left + right) / 2);
	if (card[mid] == ownCard[idx]) {
		return 1;
	}
	else if (ownCard[idx] < card[mid]) {
		return findCard(left, mid, idx);
	}
	else {
		return findCard(mid + 1, right, idx);
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		card.push_back(tmp);

	}
	cin >> M;
	for (int j = 0; j < M;++j) {
		int tmp;
		cin >> tmp;
		ownCard.push_back(tmp);
	}
	sort(card.begin(), card.end());
	for (int i = 0; i < M; ++i) {
		result.push_back( findCard(0, card.size(), i));
		
	}
	for (int i = 0; i < M;++i) {
		cout << result[i] << " ";
	}

}