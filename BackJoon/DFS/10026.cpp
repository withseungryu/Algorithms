#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int N, cnt =0, cnt_RG =0;
vector < vector<int >> adj;
vector <vector<bool>> check;
vector <vector<int>> adj_RG;
vector <vector<bool>> check_RG;
void searchBfs(int x, int y, int color) {
	if (x < N && y < N && x >= 0 && y >=0) {
		if (check[x][y] && color == adj[x][y] && x < N && y < N) {
			check[x][y] = false;
			searchBfs(x + 1, y, color);
			searchBfs(x -1 , y, color);
			searchBfs(x , y -1 , color);
			searchBfs(x, y + 1, color);

		}
		else {
			return;
		}
	}

	
	
	return;

}

void searchBfs_RG(int x, int y, int color) {
	if (x < N && y < N && x >= 0 && y >= 0) {
		if (check_RG[x][y] && color == adj_RG[x][y]) {
			check_RG[x][y] = false;
			searchBfs_RG(x + 1, y, color);
			searchBfs_RG(x - 1, y, color);
			searchBfs_RG(x, y - 1, color);
			searchBfs_RG(x, y + 1, color);

		}
		else {
			return;
		}
	}

		
	

	return;

}

int main() {
	cin >> N;
	
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	adj_RG = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j) {			
				adj[i][j] = str[j];
				if (str[j] == 'R' || str[j] == 'G') {
					adj_RG[i][j] = 'A';
				}
				else { adj_RG[i][j] = 'B'; }
						
		}		
	}
	
	check = vector<vector<bool>>(N, vector<bool>(N, true));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check[i][j]) {
				cnt++;
				searchBfs(i, j, adj[i][j]);
			}
			
		}
	}

	check_RG = vector<vector<bool>>(N, vector<bool>(N, true));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check_RG[i][j]) {
				cnt_RG++;
				searchBfs_RG(i, j, adj_RG[i][j]);
			}

		}
	}
	cout << cnt << " ";
	cout << cnt_RG;

}