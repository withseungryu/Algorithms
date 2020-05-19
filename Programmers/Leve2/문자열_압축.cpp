#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = 0;
	
	int minNum = 987654321;
	if (s.size() == 1) {
		return 1;
	}
	
	for (int i = 1; i < (s.size()); ++i) {
		vector<int> res;
		vector<int> a;
		vector<int> b;

			
			int num = 1;
			for (int j = 0; j < (s.size()); j = j + i) {

				if (j == 0) {
					//test case 5
					
					for (int k = j; k < j + i; ++k) {
						a.push_back(s[k]);
					}
				}
				else if (j+i >= (s.size())) {
					for (int k = j; k < s.size() ; ++k) {
						b.push_back(s[k]);
					}
					if (b == a) {
						num++;
						if (num > 1) {
							string tmpSt = to_string(num);
							for (int e = 0; e < tmpSt.size(); ++e) {
								res.push_back(tmpSt[e]);
							}
							
							num = 1;
						}
						for (int e = 0; e < a.size(); ++e) {
							res.push_back(a[e]);
						}
					}
					else {
						if (num > 1) {
							string tmpSt = to_string(num);
							for (int e = 0; e < tmpSt.size(); ++e) {
								res.push_back(tmpSt[e]);
							}

							num = 1;
						}
						


						for (int e = 0; e < a.size(); ++e) {
							res.push_back(a[e]);
						}
						for (int e = 0; e < b.size(); ++e) {
							res.push_back(b[e]);
						}
						
					}
				}
				else {
					for (int k = j; k < j + i; ++k) {
						b.push_back(s[k]);
					}
					if (b == a) {
						
						num++;
						a = b;
						b.clear();
						
					}
					else {
						if (num > 1) {
							string tmpSt = to_string(num);
							for (int e = 0; e < tmpSt.size(); ++e) {
								res.push_back(tmpSt[e]);
							}

							num = 1;
						}
						for (int e = 0; e < a.size(); ++e) {
							res.push_back(a[e]);
						}
						a = b;
						b.clear();
						
					}
				}
			}
			
	
		
			minNum = min(minNum, (int)res.size());
		}
	
	answer = minNum;
	return answer;
}