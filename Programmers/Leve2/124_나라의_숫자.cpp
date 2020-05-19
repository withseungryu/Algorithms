#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    while(n>0){
        int tmp = n%3;
        n = n/3;
        if(tmp == 0){
            tmp = 4;
            n = n-1;
        }
        
        answer =to_string(tmp) + answer;
    }
    return answer;
}