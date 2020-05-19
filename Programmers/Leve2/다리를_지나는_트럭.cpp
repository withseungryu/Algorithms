#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    queue<int> q;
    int truSize = truck_weights.size();
    for(int i=0; i<truSize; ++i){
        q.push(truck_weights[i]);
    }
    queue<pair<int,int>> qR;
    int total_weight = 0;
    while(!q.empty()){
        time++;
         if(!qR.empty() && time - qR.front().second == bridge_length){
            total_weight = total_weight - qR.front().first;
            qR.pop();
           
        }
        if(total_weight + q.front() <= weight){
            total_weight = total_weight + q.front();
            qR.push(make_pair(q.front() ,time));
            q.pop();
        }
      
    }
    
    while(!qR.empty()){
        time++;
        if(time - qR.front().second == bridge_length){
            qR.pop();
        }
    }
    answer = time;
    
    
    return answer;
}