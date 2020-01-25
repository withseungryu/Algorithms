#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> card;
vector<int> ownCard;
vector<int> result;
int N, M;

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
		result.push_back(upper_bound(card.begin(), card.end(), ownCard[i])-lower_bound(card.begin(),card.end(), ownCard[i]));

	}
	for (int i = 0; i < M;++i) {
		cout << result[i] << " ";
	}
	
}