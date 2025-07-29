class Solution {
    public ArrayList<Integer> asciirange(String s) {
        // code here
        int n = s.length();
        int sum = 0;
        int [] arr = new int[n];
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Character, Integer> firstIndexTillSum = new HashMap<>();
        // HashMap<Character, Integer> repeatCharacter = new HashMap<>();
        HashMap<Character, Integer> firstLastSum = new HashMap<>();
        for (int i = 0; i < n; i++){
            char c = s.charAt(i); 
            int a = c;
            sum += a;
            if (!firstIndexTillSum.containsKey(c)){
                firstIndexTillSum.put(c, sum);
            }
            else if (firstIndexTillSum.containsKey(c)){
                // repeatCharacter.put(c, 1);
                if ((sum - firstIndexTillSum.get(c) - a) != 0)
                    firstLastSum.put(c, sum - firstIndexTillSum.get(c) - a);
            }
            
            // System.out.println(a);
        }
        for (Map.Entry<Character, Integer> entry : firstLastSum.entrySet()) {
                // String name = entry.getKey();
                Integer val = entry.getValue();
                ans.add(val);
                // System.out.println(name + ": " + age);
            }
        // System.out.println(firstLastSum);
        return ans;
    }
}