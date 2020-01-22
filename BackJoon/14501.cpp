#include <iostream>
using namespace std;
#define TIME_MAX 5;
#define POINT_MAX 1000;
int main() {
	int max = 0;
	int time[15];
	int point[15];
	int n;
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> time[i];
		cin >> point[i];
	}
	for (int j = 0; j < n; j++) {
		

		for (int k = time[j]; k < n; k++) {
			result = result + point[j];
			for (int l = k; l < n;) {
				if (time[l] <= n - l) {
					
					cout << l << endl;
					
					result = result + point[l];
				}
				l = l + time[l];
				if (max <= result) {
					max = result;
				}
			}
			cout << result << endl;
			
			
		}
		result = 0;
	}
	cout << max << endl;
	return 0;
}