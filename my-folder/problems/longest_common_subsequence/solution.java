class Solution {
   // public static int t[][];
    public int longestCommonSubsequence(String text1, String text2) {
       int n = text1.length();
       int m = text2.length();

       int[][]t = new int[n+1][m+1];
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<m; j++)
           {   if(i==0|| j==0)
                 t[i][j] = 0;
           }
       }
       for(int i=1; i<=n; i++)
       {
        for(int j=1; j<=m; j++)
        {
             if(text1.charAt(i-1)== text2.charAt(j-1))
                t[i][j] = 1+ t[i-1][j-1];
             else
               t[i][j] = Math.max(t[i-1][j], t[i][j-1]); 
        }
       }
       return t[n][m];
    }

    // public int lcs(String text1, String text2, int n, int m)
    // {
    //     if(n==0 || m==0)
    //       return 0;
    //     if(t[n][m] != -1)
    //         return t[n][m];

    //      if(text1.charAt(n-1) == text2.charAt(m-1))
    //        return t[n][m] = 1 + lcs(text1, text2, n-1, m-1);
    //      else  
    //         return t[n][m] = Math.max(lcs(text1, text2, n-1,m), lcs(text1, text2, n,m-1));    
    // } 
}