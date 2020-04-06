#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int N;
int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cin >> N;
	string str;
	cin >> str; //ABC*+DE/-
	//double arr[26];
	//for (int i = 0; i < N; i++) {
	//	cin >> arr[i];
	//}
	//stack<char> st;
	//
	//int num = str.size();
	//double pivot = 0;
	//double n1 = 0;
	//double n2 = 0;
	//double n3 = 0;
	//while (num > 0) {
	//	if (str[pivot] >= 65 && str[pivot] <= 90) {
	//		st.push(str[pivot]);
	//	}
	//	else {
	//		switch (str[pivot]) {
	//		case '+':
	//			n1 = arr[st.top() - 65];
	//			st.pop();
	//			n2 = arr[st.top() - 65];
	//			st.pop();
	//			n3 = n1 + n2;
	//			st.push(n3);
	//			break;
	//		case '-':
	//			n1 = arr[st.top() - 65];
	//			st.pop();
	//			n2 = arr[st.top() - 65];
	//			st.pop();
	//			n3 = n1 - n2;
	//			st.push(n3);
	//			break;
	//		case '*':
	//			n1 = arr[st.top() - 65];
	//			st.pop();
	//			n2 = arr[st.top() - 65];
	//			st.pop();
	//			n3 = n1 * n2;
	//			st.push(n3);
	//			break;
	//		case '/':
	//			n1 = arr[st.top() - 65];
	//			st.pop();
	//			n2 = arr[st.top() - 65];
	//			st.pop();
	//			n3 = n2 / n1;
	//			st.push(n3);
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//	pivot++;
	//	num--;
	//}
	//cout << st.top();


}