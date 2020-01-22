#include <iostream>
using namespace std;

int main() {
	int n, s, u,result=0;
	int set[20];
	
	int cnt = 0;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n;i++) {
		cin >> set[i];
	}
	for (int j = 0; j < n; j++) {
		
		for (int size = 1; size <= n-j; size++) {
			u = j;
			for(int k = 0; k<size; k++){
				if (u < n) {
					result = result + set[u];
					u++;
					
				}
				else { break; }
				
			}
			if (result == s) {
				cnt++;
			}
			
			result = 0;
			u = 0;
			}
		
		
		
	}
	cout << cnt << endl;
	return 0;
}