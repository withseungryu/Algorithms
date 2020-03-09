#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int M, N;
char dna[1001][51];
//char res[51];
vector<char> res;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}


int checkDna() {
	int numA, numT,  numG,  numC;
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		numA = 0, numT = 0, numG = 0, numC = 0;
		for (int j = 0; j < N; ++j) {
			
			if (dna[j][i] == 'A') {
				numA++;
			}
			else if (dna[j][i] == 'T') {
				numT++;
			}
			else if (dna[j][i] == 'G') {
				numG++;
			}
			else {
				numC++;
			}
			
		}
		vector<pair<int, int>> pr;
		pr.push_back(make_pair(numT, 'T'));
		pr.push_back(make_pair(numG, 'G'));
		pr.push_back(make_pair(numC, 'C'));
		pr.push_back(make_pair(numA, 'A'));
		
		sort(pr.begin(), pr.end(), cmp);
		res.push_back(pr[3].second);
		cnt += pr[0].first + pr[1].first + pr[2].first;

	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> dna[i][j];
		}
	}
	int ret = checkDna();
	for (int i = 0; i < (int)res.size(); ++i) {
		cout << res[i];
	}
	cout << endl;
	cout << ret;
}