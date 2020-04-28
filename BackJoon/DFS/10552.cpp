#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, P;
int cnt = 0;
vector<vector<int>> adj;
void dom(int channel) {
	if (adj[channel].size() == 0) {
		return;
	}
	if (cnt > M) {
		cnt = -1;
		return;
	}
	cnt++;
	channel = adj[channel][0];
	dom(channel);

	
	
}

int main() {
	
	cin >> N >> M >> P;
	//P == chanel, N ==  number of people , M == number of channel
	adj = vector<vector<int>>(M+1);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	dom(P);
	cout << cnt;
	//check adj
	/*for (int i = 0; i < M; i++) {
		for (int j = 1; j < adj[i].size(); j++) {
			cout << i << " " << adj[i][j] << " ";
		}
		cout << endl;
	}*/
	
}