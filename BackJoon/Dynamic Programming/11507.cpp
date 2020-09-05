#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;

vector < vector < long >> dp;


void search() {

	for (int i = 0; i < 10; ++i) {
		dp[1][i] = 1;
	}

	for (int k = 2; k <= N; k++) {
		for (int i = 0; i < 10; ++i) {
			for (int j = i; j < 10; ++j) {
				dp[k][i] += (dp[k - 1][j]%10007);
			}
		}
	}
}



int main() {
	cin >> N;
	
	dp = vector<vector<long>>(N+1, vector<long>(10, 0));

	search();
	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (dp[N][i]%10007);
	}
	cout << (sum%10007);

}
