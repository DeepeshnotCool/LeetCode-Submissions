class Solution {
    public List<String> removeAnagrams(String[] words) {
        
        List<String> l = new ArrayList<String>();
        for(int i=0; i<words.length; i++)
        {
         l.add(words[i]);  
        }
        
        
      for(int i=1; i<=l.size()-1;)
      {
         boolean b = isAnagram(l.get(i-1), l.get(i));
          if(b== true)
          {
              l.remove(i);
          }
          else if(l.get(i-1).length() != l.get(i).length())
              i++;
          else
              i++;
          
      }
     return l;
    }
    
    public static boolean isAnagram(String str1, String str2)
    {
        if(str1.length() != str2.length())
            return false;
        HashMap<Character, Integer> hm = new HashMap<>();
        
        for(int i=0; i< str1.length(); i++)
        {
            if(hm.containsKey(str1.charAt(i)))
                hm.put(str1.charAt(i), hm.get(str1.charAt(i))+1);
            else
                hm.put(str1.charAt(i),1);
        }
        for(int i=0; i<str2.length(); i++)
        {
            if(hm.containsKey(str2.charAt(i)))
                hm.put(str2.charAt(i), hm.get(str2.charAt(i))-1);
        }
        
        Set<Character> keys = hm.keySet();
        for(Character key :keys)
        {
            if(hm.get(key) !=0)
                return false;
        }
        return true;
    }
}