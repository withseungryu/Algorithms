#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int tc;
	int tmp1[3];
	cin >> tc;
	vector<int> res;
	vector<int> tmpR;
	int result;
	for (int i = 123; i < 1000; i++) {
		res.push_back(i);
	}
	while (tc--) {
		int N, S, B;
		cin >> N >> S >> B;
		int cmS = 0, cmB = 0;
		
		int tmp2[3] = { 0 };
		int test = N;
		//�� �ڸ��� ���� �����ؼ� tmp1�� ����
		for (int i = 2; i >= 0; --i) {

			int tmp = (int)(test / (pow(10, i)));
			tmp1[i] = tmp;
			test = test - (tmp*pow(10, i));
		}
		
		for (int tmpN = 0; tmpN <= res.size(); tmpN++) {
	
			
			if (tmpN == res.size()) { res = tmpR; result = tmpR.size(); tmpR.clear();  break; }
			int tes = res.at(tmpN);
		//�� �ڸ��� ���� �����ؼ� tmp2�� ����
			for (int i = 2; i >= 0; --i) {

				int tm = (int)(tes / (pow(10, i)));
				tmp2[i] = tm;
				
				tes = tes - (tm*pow(10, i));
			}
		//�ߺ��Ǵ� ���ڰ� ������ϸ�, 0�� �����ؼ��� �ȉ�.
			if (tmp2[0] == tmp2[1] || tmp2[0] == tmp2[2] || tmp2[1] == tmp2[2] || tmp2[0] == 0 || tmp2[1] ==0 || tmp2[2] ==0) { continue; }
		// Strike�� Ball�� �Ǵ��Ͽ� cmS �� cmB�� ī��Ʈ����
			for (int i = 0; i <= 2; ++i) {
				for (int j = 0; j <= 2; ++j) {
					if (i == j) {

						if (tmp1[i] == tmp2[j]) {
							
							cmS++;
						}
					}
					else if (i != j) {
						if (tmp1[i] == tmp2[j]) {
							cmB++;
						}
					}
				}
			}
		// N�� �� ������ cmS�� cmB�� �⺻������ �ԷµǾ��� S�� B�� �����ش�.
			if (S == cmS && B == cmB) {			
				tmpR.push_back(res.at(tmpN));
			}

			cmS = 0; cmB = 0;
			
		}
	}
	cout << result;
}