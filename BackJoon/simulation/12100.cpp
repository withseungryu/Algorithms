#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int maxNum = 0;



vector<int> flush(vector<int> fl) {
	vector<int> res;
	int cnt = 0;
	for (int i = 0; i < fl.size(); ++i) {
		if (fl[i] != 0) {
			res.push_back(fl[i]);
		}
		else {
			cnt++;
		}
	}

	while (cnt > 0) {
		res.push_back(0);
		cnt--;
	}

	return res;
}

vector<vector<int>> up(vector<vector<int>> arr) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			

			vector<int> fl;
			for (int e = j; e < N; ++e) {
				fl.push_back(arr[e][i]);
			}
			fl = flush(fl);

			int f = 0;

			for (int e = j; e < N; ++e) {
				arr[e][i] = fl[f++];
			}


			if (arr[j][i] == 0) {
				break;
			}

			if (arr[j][i] == arr[j + 1][i]) {
				arr[j][i] *= 2;
				arr[j + 1][i] = 0;			
			}

		}		
	}
	return arr;


	
}


vector<vector<int>> down(vector<vector<int>> arr) {
	
	for (int i = 0; i < N; ++i) {
		for (int j = N-1; j > 0; --j) {
			


			vector<int> fl;
			for (int e = j; e >= 0; --e) {
				fl.push_back(arr[e][i]);
			}
			fl = flush(fl);

			int f = 0;

			for (int e = j; e >= 0; --e) {
				arr[e][i] = fl[f++];
			}



			if (arr[j][i] == 0) {
				break;
			}

			if (arr[j][i] == arr[j - 1][i]) {
				arr[j][i] *= 2;
				arr[j-1][i] = 0;
			}
		}
	}

	return arr;

}

vector<vector<int>> left(vector<vector<int>> arr) {


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			

			vector<int> fl;
			for (int e = j; e < N; ++e) {
				fl.push_back(arr[i][e]);
			}
			fl = flush(fl);

			int f = 0;

			for (int e = j; e < N; ++e) {
				arr[i][e] = fl[f++];
			}


			if (arr[i][j] == 0) {
				break;
			}
			
			if (arr[i][j] == arr[i][j+1]) {
				arr[i][j] *= 2;
				arr[i][j+1] = 0;
			}
		}
		
	}

	return arr;
}

vector<vector<int>> right(vector<vector<int>> arr) {
	

	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j > 0; --j) {
			

			vector<int> fl;
			for (int e = j; e >= 0; --e) {
				fl.push_back(arr[i][e]);
			}
			fl = flush(fl);

			int f = 0;

			for (int e = j; e >= 0; --e) {
				arr[i][e] = fl[f++];
			}


			if (arr[i][j] == 0) {
				break;
			}

			if (arr[i][j] == arr[i][j-1]) {
				arr[i][j] *= 2;
				arr[i][j-1] = 0;
			}
			
		}

	}

	return arr;

	
}

void searchMax(vector<vector<int>> arr) {


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] > maxNum) {
				maxNum = arr[i][j];
			}
		}

	}

}


void game(vector<vector<int>> arr, int count, int mode) {
	if (count > 5) {
		searchMax(arr);
		return;
	}

	if (mode == 0) {
		arr = up(arr);
	}
	else if(mode ==1) {
		arr = down(arr);
	}
	else if (mode == 2) {
		arr = left(arr);
	}
	else if (mode == 3) {
		arr = right(arr);
	}

	game(arr, count + 1, 0);
	game(arr, count + 1, 1);
	game(arr, count + 1, 2);
	game(arr, count + 1, 3);

}


int main() {
	cin >> N;
	
	vector<vector<int>> arr;
	arr = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}


	game(arr, 1, 0);
	game(arr, 1, 1);
	game(arr, 1, 2);
	game(arr, 1, 3);


	cout << maxNum;

}