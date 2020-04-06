#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;

int main() {
	cin >> N;
	
	
	int cnt =0 ;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		stack<int> st;
		for (int j = 0; j < str.size(); ++j) {
			if (st.empty() || st.top() != str[j]) {
				st.push(str[j]);
			}
			else if (st.top() == str[j]) { st.pop(); }
		}
		if (st.empty()) { cnt++; }
	}
	cout << cnt;
}