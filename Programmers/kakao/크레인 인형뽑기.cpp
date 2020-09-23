#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<stack<int>> st;
	int N = board.size();
	st = vector<stack<int>>(N);

	for(int i=N-1; i>=0; --i){
		for (int j = N-1; j >=0; --j) {
			if(board[i][j] != 0)
				st[j].push(board[i][j]);
		}
	}


	stack<int> ret;

	for (int i = 0; i < moves.size(); ++i) {
		if (!st[moves[i]-1].empty()) {
			int doll = st[moves[i]-1].top();
			st[moves[i] - 1].pop();
		
			if (!ret.empty()) {
				if (ret.top() == doll) {
					ret.pop();

					answer += 2;
				}
				else {
				
					ret.push(doll);
				}
				
			}
			else {
				ret.push(doll);
			}
		}
	}

	return answer;
}
