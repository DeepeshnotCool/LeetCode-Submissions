class Solution {
    public int longestPalindrome(String[] words) {
       Map<String, Integer> m = new HashMap<>();
        int count =0;
        for(int i=0; i<words.length; i++)
        {
            String revString = rev(words[i]);
            if(m.containsKey(revString) && m.get(revString) != 0){
                count += 4;
                m.put(revString, m.get(revString) - 1);
            } else{
                m.put(words[i], m.getOrDefault(words[i], 0) + 1);
            }
            // if(!m.containsKey(rev(words[i])))
            //     m.put(words[i],m.getOrDefault(words[i],0)+1);
            // else
            // {
            //     if(m.get(rev(words[i])) > 0)
            //     {   
            //        m.put(rev(words[i]),m.get(rev(words[i]))-1); 
            //        count += 4;
            //     }
            // }
        }
        for(Map.Entry<String, Integer> entry : m.entrySet())
        {
            if(isPalindrome(entry.getKey()) && entry.getValue() > 0){   
                count += 2;
                break;
            }
        }
        return count;
    }
    public static String rev(String str)
    {
        String temp ="";
        for(int i=str.length()-1; i>=0; i--)
        {
            temp += str.charAt(i);
        }
        return temp;
    }
    public static boolean isPalindrome(String str)
    {
        int i=0; 
        int j= str.length()-1;
        while(i<j)
        {
            if(str.charAt(i)!= str.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}