#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = k+1;
    int numbSize = number.size();
    while(idx > 1 && answer.size() < numbSize-k){
        char maxN = '0';
        int maxIdx = 0;
        
        for(int i=0; i<idx; ++i){
            if(number[i] > maxN){
                maxN = number[i];
                maxIdx = i;
            }
        }
        
        answer = answer + maxN;
       
        number = number.substr(maxIdx +1);
        idx = idx - maxIdx;
        
    }
    
    int tmp =0;
    while(answer.size() < numbSize-k){
        answer = answer + number[tmp];
        tmp++;
    }
    return answer;
}