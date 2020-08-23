#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> cube;
int n;

//
void clock(int i) {
	char tmp1 = cube[i][0];
	cube[i][0] = cube[i][6];
	cube[i][6] = cube[i][8];
	cube[i][8] = cube[i][2];
	cube[i][2] = tmp1;
	char tmp2 = cube[i][1];
	cube[i][1] = cube[i][3];
	cube[i][3] = cube[i][7];
	cube[i][7] = cube[i][5];
	cube[i][5] = tmp2;
}

void reClock(int i) {
	char tmp1 = cube[i][0];
	cube[i][0] = cube[i][2];
	cube[i][2] = cube[i][8];
	cube[i][8] = cube[i][6];
	cube[i][6] = tmp1;
	char tmp2 = cube[i][1];
	cube[i][1] = cube[i][5];
	cube[i][5] = cube[i][7];
	cube[i][7] = cube[i][3];
	cube[i][3] = tmp2;
}

void left(int i, int dir) {
	if (dir == -1) {
		reClock(i);
		char tmp1 = cube[0][0];
		char tmp2 = cube[0][3];
		char tmp3 = cube[0][6];

		cube[0][0] = cube[2][0];
		cube[0][3] = cube[2][3];
		cube[0][6] = cube[2][6];

		cube[2][0] = cube[1][0];
		cube[2][3] = cube[1][3];
		cube[2][6] = cube[1][6];

		cube[1][0] = cube[3][0];
		cube[1][3] = cube[3][3];
		cube[1][6] = cube[3][6];

		cube[3][0] = tmp1;
		cube[3][3] = tmp2;
		cube[3][6] = tmp3;

	}
	else {
		clock(i);
		char tmp1 = cube[0][0];
		char tmp2 = cube[0][3];
		char tmp3 = cube[0][6];

		cube[0][0] = cube[3][0];
		cube[0][3] = cube[3][3];
		cube[0][6] = cube[3][6];

		cube[3][0] = cube[1][0];
		cube[3][3] = cube[1][3];
		cube[3][6] = cube[1][6];

		cube[1][0] = cube[2][0];
		cube[1][3] = cube[2][3];
		cube[1][6] = cube[2][6];

		cube[2][0] = tmp1;
		cube[2][3] = tmp2;
		cube[2][6] = tmp3;
	}
}

void right(int i, int dir) {
	if (dir == 1) {
		clock(i);
		char tmp1 = cube[0][2];
		char tmp2 = cube[0][5];
		char tmp3 = cube[0][8];

		cube[0][2] = cube[2][2];
		cube[0][5] = cube[2][5];
		cube[0][8] = cube[2][8];

		cube[2][2] = cube[1][2];
		cube[2][5] = cube[1][5];
		cube[2][8] = cube[1][8];

		cube[1][2] = cube[3][2];
		cube[1][5] = cube[3][5];
		cube[1][8] = cube[3][8];

		cube[3][2] = tmp1;
		cube[3][5] = tmp2;
		cube[3][8] = tmp3;

	}
	else {
		reClock(i);
		char tmp1 = cube[0][2];
		char tmp2 = cube[0][5];
		char tmp3 = cube[0][8];

		cube[0][2] = cube[3][2];
		cube[0][5] = cube[3][5];
		cube[0][8] = cube[3][8];

		cube[3][2] = cube[1][2];
		cube[3][5] = cube[1][5];
		cube[3][8] = cube[1][8];

		cube[1][2] = cube[2][2];
		cube[1][5] = cube[2][5];
		cube[1][8] = cube[2][8];

		cube[2][2] = tmp1;
		cube[2][5] = tmp2;
		cube[2][8] = tmp3;
	}
}

void up(int i, int dir) {
	if (dir == 1) {
		clock(i);
		char tmp1 = cube[2][0];
		char tmp2 = cube[2][1];
		char tmp3 = cube[2][2];

		cube[2][0] = cube[5][0];
		cube[2][1] = cube[5][1];
		cube[2][2] = cube[5][2];

		cube[5][0] = cube[3][8];
		cube[5][1] = cube[3][7];
		cube[5][2] = cube[3][6];

		cube[3][8] = cube[4][0];
		cube[3][7] = cube[4][1];
		cube[3][6] = cube[4][2];

		cube[4][0] = tmp1;
		cube[4][1] = tmp2;
		cube[4][2] = tmp3;

	}
	else {
		reClock(i);
		char tmp1 = cube[2][0];
		char tmp2 = cube[2][1];
		char tmp3 = cube[2][2];

		cube[2][0] = cube[4][0];
		cube[2][1] = cube[4][1];
		cube[2][2] = cube[4][2];

		cube[4][0] = cube[3][8];
		cube[4][1] = cube[3][7];
		cube[4][2] = cube[3][6];

		cube[3][8] = cube[5][0];
		cube[3][7] = cube[5][1];
		cube[3][6] = cube[5][2];

		cube[5][0] = tmp1;
		cube[5][1] = tmp2;
		cube[5][2] = tmp3;
	}
}

void down(int i, int dir) {
	if (dir == 1) {
		clock(i);
		char tmp1 = cube[2][6];
		char tmp2 = cube[2][7];
		char tmp3 = cube[2][8];

		cube[2][6] = cube[4][6];
		cube[2][7] = cube[4][7];
		cube[2][8] = cube[4][8];

		cube[4][6] = cube[3][2];
		cube[4][7] = cube[3][1];
		cube[4][8] = cube[3][0];

		cube[3][2] = cube[5][6];
		cube[3][1] = cube[5][7];
		cube[3][0] = cube[5][8];

		cube[5][6] = tmp1;
		cube[5][7] = tmp2;
		cube[5][8] = tmp3;

	}
	else {
		reClock(i);
		char tmp1 = cube[2][6];
		char tmp2 = cube[2][7];
		char tmp3 = cube[2][8];

		cube[2][6] = cube[5][6];
		cube[2][7] = cube[5][7];
		cube[2][8] = cube[5][8];

		cube[5][6] = cube[3][2];
		cube[5][7] = cube[3][1];
		cube[5][8] = cube[3][0];

		cube[3][2] = cube[4][6];
		cube[3][1] = cube[4][7];
		cube[3][0] = cube[4][8];

		cube[4][6] = tmp1;
		cube[4][7] = tmp2;
		cube[4][8] = tmp3;
	}
}

void front(int i, int dir) {
	if (dir == 1) {
		clock(i);
		char tmp1 = cube[0][6];
		char tmp2 = cube[0][7];
		char tmp3 = cube[0][8];

		cube[0][6] = cube[4][8];
		cube[0][7] = cube[4][5];
		cube[0][8] = cube[4][2];

		cube[4][8] = cube[1][2];
		cube[4][5] = cube[1][1];
		cube[4][2] = cube[1][0];

		cube[1][2] = cube[5][0];
		cube[1][1] = cube[5][3];
		cube[1][0] = cube[5][6];

		cube[5][0] = tmp1;
		cube[5][3] = tmp2;
		cube[5][6] = tmp3;

	}
	else {
		reClock(i);
		char tmp1 = cube[0][6];
		char tmp2 = cube[0][7];
		char tmp3 = cube[0][8];

		cube[0][6] = cube[5][0];
		cube[0][7] = cube[5][3];
		cube[0][8] = cube[5][6];

		cube[5][0] = cube[1][2];
		cube[5][3] = cube[1][1];
		cube[5][6] = cube[1][0];

		cube[1][2] = cube[4][8];
		cube[1][1] = cube[4][5];
		cube[1][0] = cube[4][2];

		cube[4][8] = tmp1;
		cube[4][5] = tmp2;
		cube[4][2] = tmp3;
	}
}


void back(int i, int dir) {
	if (dir == 1) {
		clock(i);
		char tmp1 = cube[0][0];
		char tmp2 = cube[0][1];
		char tmp3 = cube[0][2];

		cube[0][0] = cube[5][2];
		cube[0][1] = cube[5][5];
		cube[0][2] = cube[5][8];

		cube[5][2] = cube[1][8];
		cube[5][5] = cube[1][7];
		cube[5][8] = cube[1][6];

		cube[1][8] = cube[4][6];
		cube[1][7] = cube[4][3];
		cube[1][6] = cube[4][0];

		cube[4][6] = tmp1;
		cube[4][3] = tmp2;
		cube[4][0] = tmp3;

	}
	else {
		reClock(i);
		char tmp1 = cube[0][0];
		char tmp2 = cube[0][1];
		char tmp3 = cube[0][2];

		cube[0][0] = cube[4][6];
		cube[0][1] = cube[4][3];
		cube[0][2] = cube[4][0];

		cube[4][6] = cube[1][8];
		cube[4][3] = cube[1][7];
		cube[4][0] = cube[1][6];

		cube[1][8] = cube[5][2];
		cube[1][7] = cube[5][5];
		cube[1][6] = cube[5][8];

		cube[5][2] = tmp1;
		cube[5][5] = tmp2;
		cube[5][8] = tmp3;
	}
}


int main() {

	int tc;
	cin >> tc;

	while (tc--) {
		cube = vector<vector<char>>(6, vector<char>(9, 0));

		for (int i = 0; i < 9; ++i) {
			cube[0][i] = 'w';
		}
		for (int i = 0; i < 9; ++i) {
			cube[1][i] = 'y';
		}
		for (int i = 0; i < 9; ++i) {
			cube[2][i] = 'r';
		}
		for (int i = 0; i < 9; ++i) {
			cube[3][i] = 'o';
		}
		for (int i = 0; i < 9; ++i) {
			cube[4][i] = 'g';
		}
		for (int i = 0; i < 9; ++i) {
			cube[5][i] = 'b';
		}

		cin >> n;
		for (int i = 0; i < n; ++i) {
			string a;
			cin >> a;
			char wh = a[0];
			int dir;
			if (a[1] == '-') {
				dir = -1;
			}
			else {
				dir = 1;
			}

			if (wh == 'U') {
				up(0, dir);
			}
			else if (wh == 'D') {
				down(1, dir);
			}
			else if (wh == 'F') {
				front(2, dir);
			}
			else if (wh == 'B') {
				back(3, dir);
			}
			else if (wh == 'L') {
				left(4, dir);
			}
			else if (wh == 'R') {
				right(5, dir);
			}


		}

		for (int i = 0; i < 9; ++i) {
			cout << cube[0][i];
			if (i == 2 || i == 5 || i == 8) {
				cout << endl;
			}
		}
	}


}
