class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> m = new HashMap<>();
        for(int i=0; i<words.length; i++)
        {
            if(!m.containsKey(words[i]))
                m.put(words[i],1);
            else
                m.put(words[i],m.get(words[i])+1);
        }
       
        LinkedHashMap<String,Integer> rm = new LinkedHashMap<>();
        m.entrySet()
  .stream()
  .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
  .forEachOrdered(x -> rm.put(x.getKey(), x.getValue()));
       
      // System.out.println(rm);
        List<String> ans = new ArrayList<>();
        List<String> result = new ArrayList<>();

        Map.Entry<String,Integer> entry = rm.entrySet().iterator().next();
        int prev = entry.getValue(); 
        System.out.println(prev);
        for (Map.Entry<String, Integer> ite : rm.entrySet())
        {
           // System.out.println(ite.getKey());
            if(ite.getValue() != prev){
                List<String> temp = ans;
                Collections.sort(temp);
                
                for(String it : temp){
                    //System.out.println(it);
                    result.add(it);
                }
                ans.clear();
                prev = ite.getValue();
            }
            ans.add(ite.getKey());
        }

        Collections.sort(ans);
        for(String it:ans){
            //System.out.println(it);
            result.add(it);
        }

        // for(String it:result){
        //     System.out.println(it);
        // }

        

        List<String> final_result = new ArrayList<>();
        for(String it : result){
            if(k == 0)
                break;
            final_result.add(it);
            k--;
         }
        return final_result;
    }
}
