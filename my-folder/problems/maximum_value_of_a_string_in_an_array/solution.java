class Solution {
    public int maximumValue(String[] strs) {
        int len =0;
        char arr[] = {'0','1','2','3','4','5','6','7','8','9'};
        boolean flag = true;
                          //  System.out.println(Integer.valueOf("0001"));
        for(int i=0; i<strs.length; i++)
        {
            String word = strs[i];
            flag = true;
            for(int j=0; j<word.length(); j++)
            {
                int ct =0; 
                for(int k=0; k<10; k++)
                {
                  if(word.charAt(j) != arr[k])
                  {
                      ct++;     
                  }    
                }
                if(ct==10)
                {  flag = false;
                   break;
                }   
            }
            if(!flag)
                { 
                   len = Math.max(len,word.length() );
                   //break;
                }
                else
                {
                    int val = Integer.valueOf(word);
                    len = Math.max(len,val);
                   // break;
                }
            System.out.println(word + "...." + len);
        }
        return len;
    }
}