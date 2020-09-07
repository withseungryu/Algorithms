#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	vector<string> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	vector<int> dp;
	dp = vector<int>(s.size()+1,0);
	int sSize = s.size();
	for (int i = sSize-1; i >= 0; --i) {
		for (int j = 0; j < a.size(); ++j) {
			int aSize = a[j].size();
			if (s[i] == a[j][0]) {
				if (i + aSize - 1 < sSize && s.substr(i, aSize) == a[j]) {
					if (i + aSize== sSize) {
						dp[i] = 1;
					}
					else if (dp[i + aSize] == 1) {
						dp[i] = 1;
					}
				}
			}
		}
	}

	cout << dp[0];
	
}
