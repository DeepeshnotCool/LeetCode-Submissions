class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List <List<Integer>>  arr = new ArrayList<List<Integer>>();
        Set <List<Integer>> s = new HashSet<List<Integer>>();
        Arrays.sort(nums);
        for(int i=0; i< nums.length-2; i++)
        {  
            int l= i+1; 
            int r= nums.length-1;
            while(l < r)
            {
                if((nums[i] + nums[l] + nums[r]) == 0)
                {
                    List<Integer> li = new ArrayList<Integer>(Arrays.asList(nums[i], nums[l], nums[r]));
                    s.add(li);
                    l++;
                    r--;
                }
                else if((nums[i] + nums[l] + nums[r]) < 0)
                    l++;
                else
                    r--;
            }
        }
        for(List<Integer> it : s)
        {
            arr.add(it);
        } 
        return arr;                  
    }
}