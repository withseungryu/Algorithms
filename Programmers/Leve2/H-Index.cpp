import java.util.ArrayList;
import java.util.Collections;
class Solution {
    public int solution(String numbers) {
        int answer = 0;
        ArrayList<String> numSt = new ArrayList<String>();
        for(int i=0; i<numbers.length(); ++i){
            numSt.add(numbers.substring(i,i+1));
        }
        Collections.sort(numSt);
        Collections.reverse(numSt);
        System.out.println(numSt.get(0));
        String maxNum = "";
        for(int i=0; i< numSt.size(); i++) {
        	maxNum = maxNum + numSt.get(i);
        }
    
        ArrayList<String> st = new ArrayList<String>();
        for(int i=2; i<=Integer.parseInt(maxNum); ++i) {
        	String tmp = numbers;
        	String str = Integer.toString(i);
        	
        	
        	boolean ok = true;
        	for(int j=0; j<str.length(); ++j) {
        		boolean tmOk = false;
//        		System.out.println(str);
//        		System.out.println(tmp);
        		for(int k=0; k<tmp.length(); ++k) {
        			
        			if(str.substring(j, j+1).equals(tmp.substring(k, k+1))) {
        				tmp = tmp.replaceFirst(str.substring(j, j+1), "");
        				
//        				System.out.println("바뀐후" + " : " + tmp);
        				tmOk = true;
        				break;
        			}
        			
        		}
        		
        		if(!tmOk) {
        			ok= false;
        			break;
        		}
        	}
        
        	if(ok) st.add(str);
        	
        }
        for(int i=0; i<st.size(); ++i) {
        	System.out.println(st.get(i));
        }
        ArrayList<String> arr_answer= new ArrayList<String>(); 
        for(int i=0; i<st.size(); ++i) {
        	boolean ok = true;
        	for(int j=2; j<Integer.parseInt(st.get(i)); j++) {
        		if(Integer.parseInt(st.get(i)) % j == 0 ) {
        			
        			ok = false;
        			break;
        		}
        	}
        	if(ok) arr_answer.add(st.get(i));
        }
        
        for(int i=0; i<arr_answer.size(); ++i) {
        	System.out.println(arr_answer.get(i));
        }
        answer = arr_answer.size();
        return answer;
    }
}