//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int arr[3];
//int dpMin[100001][3];
//
//
//int dpMax[100001][3];
//
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//
//	for (int j = 0; j < 3; j++) {
//		cin >> arr[j];
//
//	}
//
//	dpMin[0][0] = arr[0];
//	dpMin[0][1] = arr[1];
//	dpMin[0][2] = arr[2];
//
//	dpMax[0][0] = arr[0];
//	dpMax[0][1] = arr[1];
//	dpMax[0][2] = arr[2];
//
//	for (int i = 1; i < N; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> arr[j];
//
//		}
//
//	
//			dpMin[i][0] = arr[i - 1][0] + min(dpMin[0], dpMin[1]);
//			dpMin[i][1] = arr[i - 1][1] + min(dpMin[0], min(dpMin[1], dpMin[2]));
//			dpMin[i][2] = arr[i - 1][2] + min(arr[1], arr[2]);
//
//			dpMax[i][0] = arr[i - 1][0] + max(arr[0], arr[1]);
//			dpMax[i][1] = arr[i - 1][1] + max(arr[0], max(arr[1], arr[2]));
//			dpMax[i][2] = arr[i - 1][2] + max(arr[1], arr[2]);
//		
//	}
//
//	//dpMin[N][0] = dpMin[N - 1][0] + min(arr[0], arr[1]);
//	dpMin[N][1] = dpMin[N - 1][1] + min(arr[0], min(arr[1], arr[2]));
//	dpMin[N][2] = dpMin[N - 1][2] + min(arr[1], arr[2]);
//
//	dpMax[N][0] = dpMax[N - 1][0] + max(arr[0], arr[1]);
//	dpMax[N][1] = dpMax[N - 1][1] + max(arr[0], max(arr[1], arr[2]));
//	dpMax[N][2] = dpMax[N - 1][2] + max(arr[1], arr[2]);
//
//	int c1 = min(dpMin[N][0], min(dpMin[N][1], dpMin[N][2]));
//	int c2 = max(dpMax[N][0], max(dpMax[N][1], dpMax[N][2]));
//	cout << c2 << " " << c1;
//
//}


#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[3];
int dp_min_pre[3];
int dp_min_next[3];

int dp_max_pre[3];
int dp_max_next[3];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];

		}
		if (i == 0) {
			dp_min_pre[0] = arr[0];
			dp_min_pre[1] = arr[1];
			dp_min_pre[2] = arr[2];

			dp_max_pre[0] = arr[0];
			dp_max_pre[1] = arr[1];
			dp_max_pre[2] = arr[2];
		}
		else {
			dp_min_next[0] = arr[0] + min(dp_min_pre[0], dp_min_pre[1]);
			dp_min_next[1] = arr[1] + min(dp_min_pre[0], min(dp_min_pre[1], dp_min_pre[2]));
			dp_min_next[2] = arr[2] + min(dp_min_pre[1], dp_min_pre[2]);

			dp_max_next[0] = arr[0] + max(dp_max_pre[0], dp_max_pre[1]);
			dp_max_next[1] = arr[1] + max(dp_max_pre[0], max(dp_max_pre[1], dp_max_pre[2]));
			dp_max_next[2] = arr[2] + max(dp_max_pre[1], dp_max_pre[2]);

			dp_min_pre[0] = dp_min_next[0];
			dp_min_pre[1] = dp_min_next[1];
			dp_min_pre[2] = dp_min_next[2];

			dp_max_pre[0] = dp_max_next[0];
			dp_max_pre[1] = dp_max_next[1];
			dp_max_pre[2] = dp_max_next[2];

		}

	}
	int c1 = min(dp_min_next[0], min(dp_min_next[1], dp_min_next[2]));
	int c2 = max(dp_max_next[0], max(dp_max_next[1], dp_max_next[2]));
	cout << c2 << " " ;
	cout << c1;
	

}