#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i< progresses.size(); ++i){
        q.push(i);
    }
    while(!q.empty()){
        int ans = 0;
        int qSize= q.size();
        for(int i=progresses.size() - q.size(); i<progresses.size(); ++i){
            progresses[i] += speeds[i];
            if(progresses[i] >= 100 && i == q.front()){
                ans++;
                q.pop();
            }
        }
        if(qSize > q.size()){
            answer.push_back(ans);
            
        }
    }
    
    return answer;
}