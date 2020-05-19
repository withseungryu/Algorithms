#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> start;
map<vector<int>, int> dist;
vector<int> finish;

int bfs() {
	queue<vector<int>> q;
	dist[start] = 0;
	q.push(start);
	if (start == finish) {
		return 0;
	}
	while (!q.empty()) {
		
		vector<int> here = q.front();
		

		if (here == finish) {
			return dist[here];
		}
		q.pop();
		int pos=0;
		//ÁÂ
		for (int i = 0; i < 9; ++i) {
			if (here[i] == 9) {
				pos = i;
				break;
			}
		}
		
		//9ÀÇ À§Ä¡  == pos
		vector<int> pos_vec;
		if (pos == 0) {
			pos_vec.push_back(1);
			pos_vec.push_back(3);
		}
		else if (pos == 1) {
			pos_vec.push_back(0);
			pos_vec.push_back(2);
			pos_vec.push_back(4);
		}
		else if (pos == 2) {
			pos_vec.push_back(1);
			pos_vec.push_back(5);

		}
		else if (pos == 3) {
			pos_vec.push_back(0);
			pos_vec.push_back(4);
			pos_vec.push_back(6);
		}
		else if (pos == 4) {
			pos_vec.push_back(1);
			pos_vec.push_back(3);
			pos_vec.push_back(5);
			pos_vec.push_back(7);
		}
		else if (pos == 5) {
			pos_vec.push_back(2);
			pos_vec.push_back(4);
			pos_vec.push_back(8);
		}
		else if (pos == 6) {
			pos_vec.push_back(3);
			pos_vec.push_back(7);
		}
		else if (pos == 7) {
			pos_vec.push_back(4);
			pos_vec.push_back(6);
			pos_vec.push_back(8);
		}
		else if (pos == 8) {
			pos_vec.push_back(5);
			pos_vec.push_back(7);
		}
		
		
		for (int i = 0; i < pos_vec.size(); ++i) {
			vector<int> there = here;
			int tmp = there[pos];
			there[pos] = there[pos_vec[i]];
			there[pos_vec[i]] = tmp;
			if (dist.count(there) == 0) {
				dist[there] = dist[here] + 1;
				q.push(there);
			}
		}
	
	}
	return -1;

}

int main() {
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		if (tmp != 0) {
			start.push_back(tmp);
		}
		else {
			start.push_back(9);
		}
	}

	for (int i = 1; i <= 9; i++) {
		finish.push_back(i);
	}
	
	int ret = bfs();
	cout << ret;
}