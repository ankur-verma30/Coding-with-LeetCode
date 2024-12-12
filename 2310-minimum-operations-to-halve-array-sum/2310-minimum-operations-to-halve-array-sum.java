class Solution {
    public int halveArray(int[] nums) {
             PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int num : nums){
            pq.add((double)num);
        }
        long sum = 0;
        for(int num : nums){
            sum += num;
        }
        int operation = 0;
        double target=sum/2.0;
        double ans = sum;
        
       while(ans>target ){
        operation++;
        double maxheap =pq.poll();
        double div = maxheap/2.0;
        ans -= div;
         pq.add(div);


       }
       return operation;
    }
}