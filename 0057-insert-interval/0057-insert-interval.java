class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int size = intervals.length;
        int index = 0;
        List<int[]> ans = new ArrayList<>();

        while (index < size && intervals[index][1] < newInterval[0]) {
            ans.add(intervals[index++]);
        }

        while (index < size && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[index][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[index][1]);
            index++;
        }

        ans.add(newInterval);

        while (index < size) {
            ans.add(intervals[index++]);
        }

        return ans.toArray(new int[ans.size()][]);
    }
}