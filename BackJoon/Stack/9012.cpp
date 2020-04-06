#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;





int main() {
	int tc;
	cin >> tc;
	int tmp = tc;

	while (tc--) {
		stack<int> st;
		char a[50];
		vector<char> ab;
		cin >> a;

		for (int i = 0; i < 50; i++) {
			if (a[i] != '(' && a[i] != ')') {

				break;
			}

			ab.push_back(a[i]);

		}

		for (int i = 0; i < ab.size(); i++) {
			
			if (ab[i] == '(') {
				st.push('(');
			}
			else if (ab[i] == ')') {
				if (!st.empty()) {
					if (st.top() == '(') {
						st.pop();
					}
					else {
						cout << "½ÇÇà";
						cout << "NO" << endl;
						break;
					}
				}else{
					cout << "NO" << endl;
					break;
				}
			}
			if (i == (ab.size() - 1)) {
				if (!st.empty()) {
					cout << "NO" << endl;
				}
				else { cout << "YES" << endl; }
			}


		}

	}

}