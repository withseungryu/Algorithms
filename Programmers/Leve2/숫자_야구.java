import java.util.ArrayList;
class Solution {
    public int solution(int[][] baseball) {
        int answer = 0;
        ArrayList<String> st = new ArrayList<String>(); 
		//숫자야구에서 사용할수 있는 모든 숫자들 저장..
		for(int i= 123; i <= 987; ++i) {
			String str = Integer.toString(i);
			if(!str.substring(0,1).equals(str.substring(1,2)) && !str.substring(1,2).equals(str.substring(2,3)) && !str.substring(0, 1).equals(str.substring(2,3))
              && !str.substring(0,1).equals("0") && !str.substring(1,2).equals("0")
               && !str.substring(2,3).equals("0")) {
            st.add(str);				
			}
		}
		//볼, 스트라이크 몇개인지 판별한후 저장.....
		for(int i=0; i< baseball.length; i++) {
			int Num = baseball[i][0];
			int sNum = baseball[i][1];
			int bNum = baseball[i][2];
			if(st.size() == 0){
                break;
            }
			String realNum = Integer.toString(Num);			
			ArrayList<String> tmp = new ArrayList<String>();
			for(int j=0; j<st.size(); ++j) {
				String st_Num = st.get(j);

				int st_sNum = 0;
				int st_bNum = 0;
				//검사해서 s개수, b개수 파악....
				for(int k=0; k<3; ++k) {
					for(int l=0; l<3; ++l) {
						if(realNum.substring(k,k+1).equals(st_Num.substring(l,l+1))) {
							if(k==l) {
								st_sNum++;
								break;
							}else if(k!=l) {
								st_bNum++;
								break;
							}
						}
					}
				}
				if(sNum == st_sNum && bNum == st_bNum) {
					tmp.add(st_Num);
				}
				
			}
			st = tmp;		
		}
		answer = st.size();
        return answer;
    }
}