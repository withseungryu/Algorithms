#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

stack<char> st;
int N;

int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	string str;

	cin >> str;



	string result;

	stack<char> s;



	for (int i = 0; i < str.length(); i++)

	{
		if (str[i] != '+' || str[i] != '-' || str[i] != 'x' || str[i] != '/') {

		}
	}


	while (!s.empty())

	{

		result += s.top();

		s.pop();

	}



	cout << result << "\n";

	return 0;

}