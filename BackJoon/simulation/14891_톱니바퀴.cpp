#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

vector<vector<int>> chains;
vector<bool> yN;
void clock(int num) {
	int idx = num;
	int tmp = chains[idx][7];
	chains[idx][7] = chains[idx][6];
	chains[idx][6] = chains[idx][5];
	chains[idx][5] = chains[idx][4];
	chains[idx][4] = chains[idx][3];
	chains[idx][3] = chains[idx][2];
	chains[idx][2] = chains[idx][1];
	chains[idx][1] = chains[idx][0];
	chains[idx][0] = tmp;

}

void re_clock(int num) {
	int idx = num;
	int tmp = chains[idx][0];
	chains[idx][0] = chains[idx][1];
	chains[idx][1] = chains[idx][2];
	chains[idx][2] = chains[idx][3];
	chains[idx][3] = chains[idx][4];
	chains[idx][4] = chains[idx][5];
	chains[idx][5] = chains[idx][6];
	chains[idx][6] = chains[idx][7];
	chains[idx][7] = tmp;
}

void yesOrno() {
	yN = vector<bool>(3, false);

	for (int i = 0; i < 3; ++i) {
		if (chains[i][2] != chains[i + 1][6]) {
			yN[i] = true;
		}
	}
}

void check(int num, int dir) {
	yesOrno();
	int tmpDir = dir;
	int tmpDir2 = dir;
	
	if (dir == -1) {
		re_clock(num - 1);
	}
	else {
		clock(num - 1);
	}
	if (num == 1) {
		for (int i = 1; i < 4; ++i) {
			if (yN[i - 1]) {
				if (tmpDir == 1) {
					re_clock(i);
					tmpDir = -1;
				}
				else {
					clock(i);
					tmpDir = 1;
				}
			}
			else {
				break;
			}
		}
	}
	else if (num == 2) {
		if (yN[0]) {
			if (tmpDir == 1) {
				re_clock(0);
				tmpDir = -1;
			}
			else {
				clock(0);
				tmpDir = 1;
			}
		}

		for (int i = 2; i < 4; ++i) {
			if (yN[i - 1]) {
				if (tmpDir2 == 1) {
					re_clock(i);
					tmpDir2 = -1;
				}
				else {
					clock(i);
					tmpDir2 = 1;
				}
			}
			else {
				break;
			}
		}
	}
	else if (num == 3) {
		for (int i = 1; i >= 0; --i) {
			if (yN[i]) {
				if (tmpDir == 1) {
					re_clock(i);
					tmpDir = -1;
				}
				else {
					clock(i);
					tmpDir = 1;
				}
			}
			else {
				break;
			}
		}
		if (yN[2]) {
			if (tmpDir2 == 1) {
				re_clock(3);
				tmpDir2 = -1;
			}
			else {
				clock(3);
				tmpDir2 = 1;
			}
		}
	}
	else {
		for (int i = 2; i >= 0; --i) {
			if (yN[i]) {
				if (tmpDir == 1) {
					re_clock(i);
					tmpDir = -1;
				}
				else {
					clock(i);
					tmpDir = 1;
				}
			}
			else {
				break;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	chains = vector<vector<int>>(4, vector<int>(8, 0));

	for (int x = 0; x < 4; ++x) {
		string a;
		cin >> a;
		for (int i = 0; i < 8; ++i) {
			chains[x][i] = a[i]-48;
		}
	}
	
	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int num, dir;
		cin >> num >> dir;

		check(num, dir);

	}
	
	int answer = 0;
	
	for (int i = 0; i < 4; ++i) {
		
		if (chains[i][0] == 1) {
			if (i == 0) {
				answer += 1;
			}
			else if (i == 1) {
				answer += 2;
			}
			else if (i == 2) {
				answer += 4;
			}
			else {
				answer += 8;
			}
		}
	}



	cout << answer;
}
