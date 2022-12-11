class Solution {
    public int longestSquareStreak(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = -1;
        for(int i = 0; i < nums.length; i++){
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            }
            else {
                map.put(nums[i], 1);
            }
        }
        
        Arrays.sort(nums);
        for(int i = 0; i < nums.length;  i++){
            int x = nums[i];
            int c = 0;
            if(x > 10000)
                break;
            while(true){
                if(map.containsKey(x*x)){
                    c++;
                    map.remove(x*x);
                }
                else
                    break;
                x = x*x;
                if(x > 10000)
                    break;
            }
            if(c > 0)
                ans = Math.max(ans, c+1);
        }
        return ans;
        
        
        
    }
}