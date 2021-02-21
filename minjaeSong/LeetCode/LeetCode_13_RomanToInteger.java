class Solution {
    
    public int charToInt(String s){
        if(s.equals("I")){
            return 1;
        }
        else if(s.equals("V")){
            return 5;
        }
        else if(s.equals("X")){
            return 10;
        }
        else if(s.equals("L")){
            return 50;
        }
        else if(s.equals("C")){
            return 100;
        }
        else if(s.equals("D")){
            return 500;
        }
        else if(s.equals("M")){
            return 1000;
        }        
        else if(s.equals("IV")){
            return 4;
        }
        else if(s.equals("IX")){
            return 9;
        }
        else if(s.equals("XL")){
            return 40;
        }
        else if(s.equals("XC")){
            return 90;
        }
        else if(s.equals("CD")){
            return 400;
        }
        else if(s.equals("CM")){
            return 900;
        }
        else 
            return 0;
    }
    
    public int romanToInt(String s) {
        int answer = 0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length()){
                String sub = s.substring(i,i+2);
                if(sub.equals("IV") || sub.equals("IX") || sub.equals("XL") 
                		|| sub.equals("XC") || sub.equals("CD") || sub.equals("CM")){
                    answer += charToInt(sub);
                    i++;
                    continue;
                }
            }
            answer += charToInt(s.substring(i,i+1));
        }
        return answer;
    }
}