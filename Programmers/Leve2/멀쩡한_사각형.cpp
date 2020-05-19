using namespace std;

unsigned long long solution(int w,int h) {
    unsigned long long answer = 1;
    
    for(int i=1; i<w; i++){
        unsigned long long a = ((double)h*i/w);
        if(a ==0 ){
            continue;
        }
        answer = answer + a;
    }
    answer = answer -1;
    answer = answer *2 ;
    return answer;
}