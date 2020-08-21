#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<bool> visited;
vector<char> arr;
vector<char> res;

void backtrack(int len, int num_j, int num_m) {
	if (len == L && num_j >= 2 && num_m >=1) {
		for (int i = 0; i < L; ++i) {
			cout << res[i];
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < C; ++i) {
			if (len > 0 && res[len - 1] > arr[i]) {
				continue;
			}
			
			if (!visited[i]) {
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
					visited[i] = true;
					res[len] = arr[i];
					backtrack(len + 1, num_j, num_m + 1);
					visited[i] = false;
				}
				else {
					visited[i] = true;
					res[len] = arr[i];
					backtrack(len + 1, num_j + 1, num_m);
					visited[i] = false;
				}
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; ++i) {
		char tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	visited = vector<bool>(C, false);
	res = vector<char>(L, 0);

	sort(arr.begin(), arr.end());
	
	backtrack(0, 0, 0);

}
