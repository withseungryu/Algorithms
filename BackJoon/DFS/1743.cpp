#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> adj;
int cnt = 0;

void searchDfs(int x, int y) {
	
	if (x < N && y < M && x >= 0 && y >= 0) {
		if(adj[x][y] == 1){
			adj[x][y] = 0;
			cnt++;

			searchDfs(x - 1, y);
			searchDfs(x, y - 1);
			searchDfs(x + 1, y);
			searchDfs(x, y + 1);
		}
	}

	
}

int main() {
	cin >> N >> M >> K;
	adj = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < K; ++i) {
		
			int a, b;
			cin >> a >> b;
			adj[a - 1][b - 1] = 1;
		
	}

	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j) {
	//		cout << adj[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	int maximum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (adj[i][j] == 1) {
				cnt = 0;				
				searchDfs(i, j);
				maximum = max(maximum, cnt);
			}
		}
	}

	cout << maximum;


}