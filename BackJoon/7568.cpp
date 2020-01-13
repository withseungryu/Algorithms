#include <iostream>

using namespace std;
int N;

void dumbo(int dumpp[50][2], int rank[50]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dumpp[i][0] < dumpp[j][0] && dumpp[i][1] < dumpp[j][1]) {
				rank[i] += 1;
			}
		}
	}
}

int main() {
	int dumpp[50][2];
	int rank[50];
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		rank[i] = 1;
	}
	for (int i = 0; i < N; ++i) {
		cin >> dumpp[i][0] >> dumpp[i][1];
	}
	
	
	dumbo(dumpp, rank);
	for (int i = 0; i < N; i++) {
		cout << rank[i] << " ";
	}


}

