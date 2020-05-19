#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    vector<int> pr;
    for(int i=0; i<priorities.size(); ++i){
        pr.push_back(priorities[i]);
    }
    sort(pr.begin(), pr.end(), greater<int>());
    int max_priority= 0;
    for(int i=0; i<priorities.size(); ++i){
        q.push(i);
      
    }
    int prIdx = 0;
    //max_priority  가장 높은 우선순위....
    while(!q.empty()){
        if(priorities[q.front()] == pr[prIdx]){
             answer++;
            if(q.front() == location){
                break;
            }
            q.pop();       
            prIdx++;
           
        }else{
            q.push(q.front());
            q.pop();            
        }
    }
    return answer;
}