class Solution {
    int captureForts(int[] forts) {
        int ans = 0;
        for(int i = 0 ; i < forts.length-1 ; i++)
        {
            int count = 0;
            if(forts[i] == 1 || forts[i] == -1)
            {
                for(int j = i+1; j < forts.length; j++)
                {
                    if(forts[j] == 0)
                        count++;
                    else if(forts[i] == forts[j]){
                        break;
                    } else {
                        ans =Math.max(ans, count);
                        break;
                    }
                }
            }
        }
        return ans;
    }
    // public int captureForts(int[] forts) {
    //     int ct =0; int count=0;
    //     for(int i=0; i<forts.length; i++)
    //     {
    //         if(forts[i]==1)
    //         {   int j=i+1;
    //             while(j<forts.length && forts[j++] ==0)
    //             {
    //                 ct++;
    //             }
    //       //   System.out.println(ct);
    //          if(j<forts.length &&forts[j]==-1)
    //            count = Math.max(ct,count);
    //             //break;
    //       //   System.out.println(count);
    //         }
    //     }
    //  //   System.out.println(count);
    //     ct =0;
    //     for(int i=forts.length-1; i>=0; i--)
    //     {
    //         if(forts[i]==1)
    //         {   int j=i-1;
    //             while(j>=0 && forts[j--] ==0)
    //             {
    //                 ct++;
    //             }
    //          if(j>=0 && forts[j]==-1)
    //           count = Math.max(ct,count);
    //          System.out.println(count);
    //           //  break;
    //         }    
    //     }
    //    System.out.println(count);
    //     return count;
    // }
}