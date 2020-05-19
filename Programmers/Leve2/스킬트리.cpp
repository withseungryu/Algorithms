#include <string>
#include <vector>
#include <queue>
using namespace std;



int solution(string skill, vector<string> skill_trees) {
    queue<int> tmp_q;
    vector<int> pre(26,0);
    int answer = 0;
    
    for(int i=0; i<skill.size(); ++i){
        tmp_q.push(skill[i]);
        int idx = skill[i] - 65;
        pre[idx] = 1;
    }
    
    for(int i=0; i<skill_trees.size(); ++i){
        queue<int> q = tmp_q;
        bool ok = true;
        for(int j=0; j<skill_trees[i].size(); ++j){
            int idx = skill_trees[i][j] - 65;
            if(pre[idx] == 1){
                if(q.empty()){
                    break;
                }
                if(skill_trees[i][j] == q.front()){
                    q.pop();
                }else{
                    ok = false;
                    break;
                }
            }
        }
        if(ok)
            answer++;
        
    }
    

    return answer;
}