#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> tuples;
	int max_num = 0;
	tuples = vector<vector<int>>(501, vector<int>(0));
	int i = 1;
	while(i <= s.size()-1){

		vector<int> saver;
		if (s[i] == '{') {
			string tmp = "";
			int cnt = 0;
			
			while (1) {

				i++;
				if (s[i] == '}') {
					saver.push_back(stoi(tmp));
					break;
				}	
				if (s[i] == ',') {
					cnt++;
	
					saver.push_back(stoi(tmp));
					tmp = "";
				}
				else {
					tmp.push_back(s[i]);
				}
			
			}
			max_num = max(max_num, cnt);
			tuples[cnt + 1] = saver;
		}
		i=i+2;

	}

	map<int, int> m;
	for (int i = 1; i <= max_num + 1; ++i) {
		
		for(int j=0; j<tuples[i].size(); ++j){
			m[tuples[i][j]] += 1;
		}
	}

	vector<pair<int, int>> ret;
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		ret.push_back(make_pair(itr->second, itr->first));

	}

	sort(ret.begin(), ret.end());
	reverse(ret.begin(), ret.end());

	for (int i = 0; i < ret.size(); ++i) {
		answer.push_back(ret[i].second);
	}


	return answer;
}
