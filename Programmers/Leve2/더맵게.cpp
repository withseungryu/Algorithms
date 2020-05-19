#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<scoville.size(); ++i){

        pq.push(scoville[i]);
    }
    while(pq.size() > 1 && pq.top() <K){
        answer++;
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        if(a==0 && b==0){
            answer = -1;
            break;
        }
        long long c = a + (b*2);
        pq.push(c);
    }
    if(pq.size()==1 && pq.top() < K){
        return -1;
    }
    return answer;
}