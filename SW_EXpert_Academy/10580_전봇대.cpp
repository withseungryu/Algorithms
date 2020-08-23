#include<iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main(int argc, char** argv)
{
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
 
    vector<int> res;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int N;
        cin >> N;
        int answer = 0;
        vector<pair<int, int>> line;
        for (int i = 0; i < N; ++i) {
            int a, b;
            cin >> a >> b;
 
            if (i == 0) {
                line.push_back(make_pair(a, b));
                 
            }else{
 
            for (int j = 0; j < line.size(); ++j) {
                if (line[j].first > a && line[j].second < b) {
                    answer++;
                }
                else if (line[j].first <a && line[j].second > b) {
                    answer++;
                }
            }
                 
            line.push_back(make_pair(a, b));
 
            }
        }
 
        res.push_back(answer);
 
 
    }
 
    for(int i=0; i<res.size(); ++i){
        cout << '#' << i+1 << " " << res[i] << endl;
    }
    return 0;
}
