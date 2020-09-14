#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> keyPad = { {1,2,3},{4,5,6},{7,8,9},{10, 0, 11} };

int rLeft = 10;
int rRight = 11;

bool check(int to, bool bHand) {
	pair<int, int> kLeft;
	pair<int, int> kRight;
	pair<int, int> kTo;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (rLeft == keyPad[i][j]) {
				kLeft = make_pair(i, j);
			}
			if (rRight == keyPad[i][j]) {
				kRight = make_pair(i, j);
			}
			if (to == keyPad[i][j]) {
				kTo = make_pair(i, j);
			}

		}
	}
		
	
	
	if ((abs(kLeft.first - kTo.first) + abs(kLeft.second - kTo.second)) > (abs(kRight.first - kTo.first) + abs(kRight.second - kTo.second))) {
		return true;
	}
	else if ((abs(kLeft.first - kTo.first) + abs(kLeft.second - kTo.second)) < (abs(kRight.first - kTo.first) + abs(kRight.second - kTo.second))) {
		return false;
	}
	else if((abs(kLeft.first - kTo.first) + abs(kLeft.second - kTo.second)) == (abs(kRight.first - kTo.first) + abs(kRight.second - kTo.second))) {
		if (bHand) {
			return true;
		}
		else {
			return false;
		}
	}


}


char move(int to, bool bHand) {
	if (to == 1 || to == 4 || to == 7) {
		rLeft = to;
		return 'L';
	}
	else if (to == 3 || to == 6 || to == 9) {
		rRight = to;
		return 'R';
	}
	else {
		if (check( to, bHand)) {
			rRight = to;
			return 'R';
		}
		else {
			rLeft = to;
			return 'L';
		}
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	bool bHand = false;
	if (hand.compare("right")==0) {
		bHand = true;
	}

	cout << bHand << endl;
	for (int i = 0; i < numbers.size(); ++i) {
		answer += move(numbers[i], bHand);
		cout << rLeft << " : " << rRight << endl;
	}

	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << endl;

	return answer;
}

int main() {
	vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	string hand = "left";
	solution(numbers, hand);
}