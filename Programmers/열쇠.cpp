#include <string>
#include <vector>

using namespace std;


int m;
int n;

vector<vector<int>> clock(vector<vector<int>> key) {
	vector<vector<int>> tmp;
	tmp = vector<vector<int>>(m, vector<int>(m, 0));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			int idy;
			if (j == 0) {
				idy = 2;
			}
			else if (j == 1) {
				idy = 1;
			}
			else {
				idy = 0;
			}
			tmp[i][j] = key[idy][i];
		}
	}

	return tmp;
}


vector<vector<int>> set(vector<vector<int>> matrix, vector<vector<int>> key, int x, int y) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <m; ++j) {
			matrix[x + i][y + j] += key[i][j];
		}
	}
	return matrix;
}

bool check(vector<vector<int>> matrix) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[m - 1 + i][m - 1 + j] != 1) {
				return false;
			}
		}
	}
	return true;

}
void rotateKey(vector<vector<int>> &key) {
        
    vector<vector<int>> tmp(m, vector<int>(m));
 
    for (int j =m - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            tmp[i][j] = key[m - j - 1][i];
        }
    }
 
    key = tmp;
}
 

bool execute(vector<vector<int>> matrix, vector<vector<int>> key) {
	for (int x = 0; x < 4; ++x) {
    for (int i = 0; i < matrix.size()-key.size()+1; ++i) {
		for (int j = 0; j < matrix.size()-key.size()+1; ++j) {
			
				vector<vector<int>> tmp = set(matrix, key, i, j);
				if (check(tmp)) {
					return true;
				}
				
			}			
		}
        rotateKey(key);
	}
	return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	m = key.size();  n = lock.size();
	vector<vector<int>> matrix;
    int boardSize = (2*m)+n-2;
	matrix = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));

    bool ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
            if(lock[i][j] != 1) ok =false;
			matrix[m - 1 + i][m - 1 + j] = lock[i][j];
		}
	}
    
    if(ok) answer=true;
	else answer = execute(matrix, key);
	return answer;
}
