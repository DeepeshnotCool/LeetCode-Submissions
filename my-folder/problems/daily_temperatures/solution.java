class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Pair> st = new Stack<>();
        int n = temperatures.length;
    
        int[] answer = new int[n];
        for(int i=n-1; i>=0; i--)
        {  
            while(!st.isEmpty() && st.peek().first<= temperatures[i])
             {   st.pop();}

             if(st.isEmpty())
               answer[i]=0;
             else
               { 
                   answer[i] = st.peek().second - i;
      //  System.out.println( temperatures[i]+ "..." +st.peek() + "..." + answer[i] +".." + i);
        }
             st.push(new Pair(temperatures[i],i));        
        }
        return answer;
    }
}
class Pair
{
    int first;
    int second;
    public Pair(int first,int second)
    {
        this.first = first;
        this.second = second;
    }
}