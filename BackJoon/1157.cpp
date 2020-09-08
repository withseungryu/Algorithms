#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	map<char, int> m;
	map<char, int> ::iterator itr;
	for (int i = 0; i < s.size(); ++i) {
		char tmp = s[i];
		if (tmp >= 97 && tmp <= 122) {
			tmp = s[i] - 32;
		}

		if (m.count(tmp) == 0) {
			m.insert(pair<char, int>(tmp, 1));
		}
		else {
			m.find(tmp)->second++;
		}
	}

	vector<pair<int,char>> res;
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		res.push_back(make_pair(itr->second, itr->first));
	}

	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());

	if (res.size()>=2 && res[0].first == res[1].first) {
		cout << "?" ;
	}
	else {
		cout << res[0].second;
	}

}
