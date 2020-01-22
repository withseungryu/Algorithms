#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	int ok = 0;
	for (int i = N; i > 3 ; --i) {

		string tmp = to_string(i);
		
		for (int j = 0; j < tmp.size(); j++) {
			string t1 = tmp.substr(j, 1);
			if (t1 == "4" || t1 == "7") {
				if (j == (tmp.size() - 1)) { cout << i; ok = 1; break; }
				continue;
			}
			else { break; }
			break;
		}
		if (ok == 1) {
			break;
		}
		
	}
}



