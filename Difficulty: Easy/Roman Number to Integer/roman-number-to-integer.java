class Solution {
    public int romanToDecimal(String s) {
        // code here
        int no =0;
        int n=s.length();
        Map<Character, Integer>m=new HashMap<>();
        m.put('I',1);
        m.put('V',5);
        m.put('X',10);
        m.put('L',50);
        m.put('C',100);
        m.put('D',500);
        m.put('M',1000);
        for(int i=0;i<n;i++){
            if(i<n-1){
                char ch = s.charAt(i);
                char ch2 = s.charAt(i+1);
                if(ch==ch2){
                    no+=m.get(ch)+m.get(ch);
                    i++;
                }
                else if(m.get(ch)>m.get(ch2)){
                    no+=m.get(ch);
                }
                else{
                    int val = m.get(ch2) - m.get(ch);
                    no+=val;
                    i++;
                }
            }else{
                no+=m.get(s.charAt(i));
            }
        }
        
        return no;
    }
}