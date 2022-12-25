class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int  n  = words.length, min_dis = -1, dis =0;
        if(n==0)
            return -1;
        for(int i=0; i<n; i++)
        {
            if(words[i].equals(target))
            {
                dis = Math.abs(i-startIndex);
                dis = Math.min(dis,n-dis);
                if(min_dis==-1)
                    min_dis = dis;
                else
                    min_dis = Math.min(min_dis,dis);
            }
        }
        return min_dis;
        // int left=0, right =0, ind =-1;
        // int n = words.length;
        // for(int i=startIndex;i<=2*n-1; i++)
        // {
        //     if(i>=n)
        //         i= i%n;
        //     if(words[i].equals(target))
        //     {   
        //         ind =i;
        //         left++;
        //          break;
        //     }
        //     left++;
        // }
        // if(ind==-1) return -1;
        // for(int i=startIndex; i<=2*n-1;i--)
        // {    
        //     if(i>-n)break;
        //     if(i <= -n && i<0)
        //         i= i+n;
        //     if(words[i].equals(target))
        //     {   
        //         ind =i;
        //         right++;
        //          break;
        //     }
        //     right++;
        // }
        // return Math.min(left,right);
    }
}