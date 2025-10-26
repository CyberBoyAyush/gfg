class Solution {

    public int minOperations(int[] arr) {

        // code here

       double sum =0;

       PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());

       for(int x:arr){

           sum += x;

           pq.add((double)x);

       }

       

       int times =0;

       double target = sum/2;

       while(sum>target){

           double decValue = pq.poll();

           double newValue = decValue/2;

           

           sum -=newValue;

           pq.add(newValue);

           times++;

       }

       return times;

       

    }

}