#include <vector>
#include <math.h>
using namespace std;

int number_of_area;
int max_size_of_one_area;
int max_size_tmp = 0;
vector<vector<bool>> discovered;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int startx, int starty, int m, int n, vector<vector<int>> picture){
    max_size_tmp++;
    discovered[startx][starty]= true;
    
    for(int i=0; i<4; i++){
        int therex = startx + dir[i][0];
        int therey = starty + dir[i][1];
        if( therex >=0 && therey >=0 && therex < m && therey < n && discovered[therex][therey] == false
            &&picture[startx][starty] != 0 && picture[startx][starty] == picture[therex][therey]
          ){
            dfs(therex,therey, m , n, picture);
            
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    discovered = vector<vector<bool>>(m, vector<bool>(n, false));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(picture[i][j] != 0 && discovered[i][j] == false){
                dfs(i,j,m,n, picture);
                max_size_of_one_area = max(max_size_of_one_area, max_size_tmp);
                max_size_tmp = 0;
                number_of_area++;
            }
            
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}