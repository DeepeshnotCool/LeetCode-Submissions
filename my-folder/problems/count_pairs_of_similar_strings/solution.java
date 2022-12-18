class Solution {
    public int similarPairs(String[] words) {
        
        int ans =0;
        for(int i=0; i<words.length-1;i++ )
        {
            String s = words[i];
            int[] arr = new int[26];
            for(int j=0; j<s.length(); j++)
            {
                arr[s.charAt(j)-'a'] =1;
            }
            for(int k=i+1; k< words.length; k++)
            {
                String t = words[k];
                int[] arr1 = new int[26];
                for(int l=0; l<t.length(); l++)
                {
                    arr1[t.charAt(l)-'a'] =1;
                }
                int flag =0;
                for(int l=0; l<26; l++)
                {
                    if(arr1[l] != arr[l])
                    {
                        flag =1;
                        break;
                    }
                }
                if(flag==0)
                    ans++;
            }
        }
        return ans;
//         int ct =0;
       
        
//         for(int i=0; i<words.length; i++)
//         {    boolean flag = true;
//             String temp = words[i];
//             char[] arr = new char[26];
//             for(int j=0; j<temp.length(); j++)
//             {
//                 arr[temp.charAt(j)-'a']++;
//             }
//          //   System.out.println(arr[temp.charAt(0)-'a']);
//             for(int k= i+1; k<words.length; k++)
//             {   
//                 String temp1 = words[k];
                
//                 for(int l=0; l<temp1.length(); l++)
//                 {
//                     if(arr[temp1.charAt(l)-'a'] >0)
//                         continue;
//                     else
//                     { 
//                       flag = false;
//                       break;
//                     }       
//                 }
              
//                 if(flag==true)
//                   ct++;
//             }
//          // Arrays.fill(arr,'.');
//         }
//         return ct;
    }
}