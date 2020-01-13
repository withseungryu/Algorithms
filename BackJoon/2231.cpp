#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N;
	
	
	cin >> N;


	for (int i = 1; i < 1000000; i++) {
		int res = 0;
		int gene[7] = { 0 };
		int tmpI = i;
		for (int j = 6; j >= 0; --j) {
			
			
			gene[j] = (int)(tmpI / (pow(10, j)));
			tmpI = tmpI - (gene[j]*(pow(10,j)));

		}
		for (int j = 0; j < 6; j++) {
			res += gene[j];
			
		}
		res = res + i;
		if (res == N) { cout << i << endl;  return 0; }
		
	}
	cout << 0;
	return 0;
	
}