class Solution {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        TreeMap<Integer,Integer> map = new TreeMap<>();
        int n = obstacles.length;

        map.put(0, 0);
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {

            // find best dp value for height <= obstacles[i]
            Integer key = map.floorKey(obstacles[i]);
            int value = map.get(key) + 1;
            ans[i] = value;

            // remove dominated entries
            Map.Entry<Integer, Integer> entry = map.ceilingEntry(obstacles[i]);
            while (entry != null && entry.getValue() <= value) {
                map.remove(entry.getKey());
                entry = map.ceilingEntry(obstacles[i]);
            }

            // add dp value for current height
            map.put(obstacles[i], value);
        }

        return ans;
    }
}
