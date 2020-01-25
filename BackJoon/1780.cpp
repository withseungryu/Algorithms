#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
bool checkNum(int firstx, int firsty, int N, int number);
int N;
int mo = 0; int o = 0; int z = 0;
int paper[2200][2200];

int findPaper(int firstx, int firsty, int N) {
	
	if (checkNum(firstx, firsty, N, -1)) {
		mo++;
		return 0;
	}
	else if (checkNum(firstx, firsty, N, 0)) {
		o++;
		return 0;
	}
	else if (checkNum(firstx, firsty, N, 1)) {
		z++;
		return 0;
	}
	else if (N == 1) return 0;
	else{
		for (int i = firstx; i < firstx+N; i = i + (N/3)) {
			for (int j = firsty; j < firsty+N; j = j + (N/3)) {
				findPaper(i, j, N / 3);
			}
		}
	}
	return 0;
}
bool checkNum(int firstx, int firsty, int N, int number) {
	bool ok = true;
	for (int i = firstx; i < firstx+N; i++) {
		for (int j = firsty; j < firsty+N; j++) {
			if (paper[i][j] != number) {
				ok = false;
				return ok;
			}
		}
	}
	return ok;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	findPaper(0, 0, N);
	cout << mo << endl;
	cout << o << endl;
	cout << z ;
}
