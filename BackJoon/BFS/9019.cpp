#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int A, B;

vector<pair<int, char>> parent;

int shift_L(int here) {
	int n = (here % 1000);
	int temp = (int)(here / 1000);

	return temp + n*10;
}

int shift_R(int here) {
	int n = (int)(here / 10);
	int temp = (int)(here % 10);

	return n+(temp*1000);
}
vector<char> shortest_Path(int v) {
	vector<char> path;
	while (parent[v].first != v) {
		path.push_back(parent[v].second);
		v = parent[v].first;
		
	}
	reverse(path.begin(), path.end());
	return path;
}
void bfs() {
	vector<int> dist;
	dist = vector<int>(10000, 0);

	parent = vector < pair<int, char>>(10000, make_pair(0, 0));
	
	queue<int> q;
	dist[A] = 1;
	parent[A] = make_pair(A, 0);
	q.push(A);
	while (!q.empty()) {
		int here = q.front();
		if (here == B) {
			break;
		}
		q.pop();
		//D
		if (here != 0) {
			int there_D = (here * 2);
			if (there_D > 9999) {
				there_D = there_D % 10000;
			}
			if (there_D >= 0 && there_D < 10000 && dist[there_D] == 0) {
				dist[there_D] = 1;
				parent[there_D] = make_pair(here, 'D');
				q.push(there_D);
			}
		}
		int there_S = here - 1;
		if (there_S == -1) {
			there_S = 9999;
		}
		if (there_S >= 0 && there_S < 10000 && dist[there_S] == 0) {
			dist[there_S] =  1;
			parent[there_S] = make_pair(here, 'S');
			q.push(there_S);
		}
		if (here != 0) {
			int there_L = shift_L(here);
			if (there_L >= 0 && there_L < 10000 && dist[there_L] == 0) {
				dist[there_L] = 1;
				parent[there_L] = make_pair(here, 'L');
				q.push(there_L);
			}
		}
		if (here != 0) {
			int there_R = shift_R(here);
			if (there_R >= 0 && there_R < 10000 && dist[there_R] == 0) {
				dist[there_R] = 1;
				parent[there_R] = make_pair(here, 'R');
				q.push(there_R);
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int tc;
	cin >> tc;

	while (tc--) {
		cin >> A >> B;

		bfs();
		vector<char> res = shortest_Path(B);
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i];
		}
		cout << endl;
	}

	

}