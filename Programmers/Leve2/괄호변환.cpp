#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


string splitFun(string p){
    string answer = "";
    stack<char> st;
    if(p == ""){
        return "";
    }
    string u = "";
    string v = "";
    int leftNum = 0;
    int rightNum = 0;
    for(int i=0; i<p.size(); ++i){
        if(p[i] == '('){
            st.push('('); 
            leftNum++;
        }
        else{ if(!st.empty()) st.pop(); rightNum++;}
        u = u+ p[i];
        if(leftNum == rightNum){
            p = p.substr(i+1);
            break;
        }
    }
    v= p;
    if(!st.empty()){
        string tmp = "";
        tmp = tmp + "(";
        tmp = tmp + splitFun(v);
        tmp = tmp  +  ")";
        for(int i=1; i<u.size()-1; ++i){
            if(u[i] == '('){
                tmp = tmp + ")";
            }else{
                tmp = tmp +"(";
            }
        }
        answer = answer + tmp;
        return answer;
    }else{
   
        return answer = u + splitFun(v);
        
       
    }
    
    
    
}

string solution(string p) {
    
    string answer = "";
    answer = splitFun(p);
    return answer;
}