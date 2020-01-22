#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int N;
bool ok;
void weirdPrime(int first, int n);
bool prime(int n);

int main() {
	cin >> N;
	int first_c[4] = { 2,3,5,7 };
	for (int i = 0; i < 4;i++) {
		weirdPrime(first_c[i], N - 1);
	}



}
void weirdPrime(int first, int n) {
	if (n == 0) { cout << first << endl; }
	for (int i = 1; i < 10;i++) {
		int tmp = first * 10 + i;
		if (prime(tmp)) {
			weirdPrime(tmp, n - 1);
		}
	}
	
}

bool prime(int n) {
	int cmp = false;
	double last = (int)(n / 2);
	if (n == 2 || n==3) {
		return true;
	} 
	for (int i = 2; i <= last; i++) {
		
		if ((n%i) == 0) {
			break;
		}
		if (i == last) {
			cmp = true;
		}	
	}
	return cmp;
}