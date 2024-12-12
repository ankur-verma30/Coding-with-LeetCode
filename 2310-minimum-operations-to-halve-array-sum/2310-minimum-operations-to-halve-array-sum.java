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
        double ans = 0;
       while(ans <= (double) sum/2.0){
        operation++;
        double maxheap =pq.poll();
        double div = maxheap/2.0;
        ans += div;
         pq.add(div);
         if(ans==(double)sum/2.0) break;


       }
       return operation;
    }
}