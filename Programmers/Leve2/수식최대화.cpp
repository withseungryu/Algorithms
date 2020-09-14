#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long calc(long a, long b, char op) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else {
		return a * b;
	}
}

long long execute(vector<long long> numbers, vector<char> rOp , vector<char> op) {

	for (int i = 0; i < op.size(); ++i) {
		char cmp = op[i];

		for (int j = 0; j < rOp.size(); ++j) {
			if (cmp == rOp[j]) {
				long long tmp = calc(numbers[j], numbers[j + 1], cmp);
				numbers[j + 1] = tmp;
				numbers.erase(numbers.begin() + j);
				rOp.erase(rOp.begin()+j);
				j = j - 1;
			}
		}
		
	}

	return numbers[0];
}


long long solution(string expression) {
	long long answer = 0;

	vector<long long> numbers;
	set<char> tmpOp;
	vector<char> rOp;
	string tmp;
	for (int i = 0; i < expression.size(); ++i) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			tmp += expression[i];
		}
		else {
			numbers.push_back(stoi(tmp));
			tmp = "";
			tmpOp.insert(expression[i]);
			rOp.push_back(expression[i]);
		}

		if (i == expression.size() - 1) {
			numbers.push_back(stoi(tmp));
		}

	}

	vector<char> op;
	for (auto itr = tmpOp.begin(); itr != tmpOp.end(); ++itr) {
		
		op.push_back(*itr);
	}

	do {

		long long ret = abs(execute(numbers, rOp, op));
		answer = max(answer, ret);

	} while (next_permutation(op.begin(), op.end()));

	

	return answer;
}

int main() {
	string expression = "50*6-3*2";


	cout << solution(expression);

}
