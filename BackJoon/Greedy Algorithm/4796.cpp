#include <iostream>
#include <vector>
using namespace std;

int L, P, V;
vector<int> res;

int camping(int L, int P, int V) {
	int l = L; int p = P; int v = V;
	int ret = 0;
	
	while (v > 0) {
		int tmp = v;
		v = v - p;
		if (v  >= 0) {
			ret = ret + l;
		}
		else{
			if (tmp  >= l) {
				ret = ret + l;
			}
			else {
				ret = ret + (tmp);
			}
		}
	}
	return ret;

}

int main() {
	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		res.push_back(camping(L, P, V));
	}
	for (int i = 0; i < (int)res.size(); ++i) {
		printf("Case %d: %d\n", i+1, res[i]);
	}
}