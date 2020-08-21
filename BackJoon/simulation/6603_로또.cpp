#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector<int> arr;
vector<bool> visited;
vector<int> res;
void backtrack(int len) {

	if (len == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i =1; i <= k; ++i) {
			
			if (len > 0 && res[len - 1] > arr[i]) {
				continue;
			}
			if (!visited[i]) {
				visited[i] = true;
				res[len] = arr[i];
				backtrack(len + 1);
				visited[i] = false;
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {

		cin >> k;
		if (k == 0) {
			break;
		}
		arr = vector<int>(14, 0);
	
		for (int i = 1; i <= k; ++i) {
			cin >> arr[i];
		}

		res = vector<int>(k + 1, 0);
		visited = vector<bool>(k + 1, false);

		backtrack(0);

		cout << endl;

	}
}
