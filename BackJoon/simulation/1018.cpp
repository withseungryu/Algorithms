#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> arr;
int N, M;

int checkArrFirst(vector<vector<char>> tmp) {

	int cnt = 0;

	char base;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {

			if (i==0 && j==0) {
				base = tmp[i][j];
				continue;
			}


			if (base=='B') {
				if (tmp[i][j] == 'B') {				
					cnt++;
					tmp[i][j] = 'W';
					base = tmp[i][j];					
				}
				else {
					base = tmp[i][j];
				}
			}
			else{
				if (tmp[i][j] == 'W') {
					cnt++;
					tmp[i][j] = 'B';
					base = tmp[i][j];
				}
				else {
					base = tmp[i][j];
				}
			}

			if (j == 7) {
				if (base == 'B') {
					base = 'W';
				}
				else {
					base = 'B';
				}
			}
			
		}

	}

	return cnt;
	
}

int checkArrSecond(vector<vector<char>> tmp) {

	int cnt = 0;

	char base;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {

			if (i == 0 && j == 0) {
				cnt++;
				if (tmp[i][j] == 'B') {
					base = 'W';
				}
				else {
					base = 'B';
				}
				
				continue;
			}


			if (base == 'B') {
				if (tmp[i][j] == 'B') {
					cnt++;
					tmp[i][j] = 'W';
					base = tmp[i][j];
				}
				else {
					base = tmp[i][j];
				}
			}
			else {
				if (tmp[i][j] == 'W') {
					cnt++;
					tmp[i][j] = 'B';
					base = tmp[i][j];
				}
				else {
					base = tmp[i][j];
				}
			}

			if (j == 7) {
				if (base == 'B') {
					base = 'W';
				}
				else {
					base = 'B';
				}
			}

		}

	}

	return cnt;

}


int ches() {
	int minNum = 100;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			vector<vector<char>> tmp;
			tmp = vector<vector<char>>(8, vector<char>(8, 0));
			
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					tmp[k][l] = arr[i + k][j + l];
				}
			}

			minNum = min(minNum, min(checkArrFirst(tmp),checkArrSecond(tmp)));
		}
	}
	return minNum;
}


int main() {
	
	cin >> N >> M;
	arr = vector<vector<char>>(N, vector<char>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	

	cout << ches();
}
