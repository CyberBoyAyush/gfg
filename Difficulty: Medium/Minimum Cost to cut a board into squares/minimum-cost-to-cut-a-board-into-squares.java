class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
       Arrays.sort(x);
       Arrays.sort(y);
       reverse(x);
       reverse(y);
       int i=0;
       int j=0;
       int hor=1;
       int ver=1;
       int totalcost=0;
       while(i<x.length && j<y.length){
           if(x[i]>=y[j]){
               totalcost+=x[i]*hor;
               ver++;
               i++;
           }else{
               totalcost+=y[j]*ver;
               hor++;
               j++;
           }
       }
        while(i<x.length){
            totalcost+=x[i]*hor;
            ver++;
            i++;
        }
        while(j<y.length){
            totalcost+=y[j]*ver;
            hor++;
            j++;
        }
        return totalcost;
    }
    public static void reverse(int[] arr){
        int left =0;
        int right=arr.length-1;
        while(left<right){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
            
        }
    }
    public static void main(String[] args){
        int n1=4,m1=6;
        int x1[]={2,1,3,1,4};
        int y1[]={4,1,2};
        System.out.println(minCost(n1,m1,x1,y1));
         int n2=4,m2=4;
        int x2[]={1,1,1};
        int y2[]={1,1,1};
        System.out.println(minCost(n2,m2,x2,y2));
        
    }
}

