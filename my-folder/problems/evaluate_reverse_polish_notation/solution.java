class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens.length ==1)
            return Integer.valueOf(tokens[0]);
       Stack<String>  st1 = new Stack<>();
       Stack<String> st2 = new Stack<>();
        int val=0;
        int num1 =0;
        int num2 =0;
        
       for(int i=0; i<tokens.length; i++)
       {
           char ch [] = tokens[i].toCharArray();
           if(tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*")  || tokens[i].equals("/"))
           {
               st2.push(st1.pop());
               
               if(!st1.isEmpty())
                 num1 = Integer.valueOf(st1.pop());
               if(!st2.isEmpty())
                 num2 = Integer.valueOf(st2.pop());
               
               if(ch[0]=='+')
                   val = num1 +num2;
               else if(ch[0] =='-')
                   val = num1- num2;
               else if(ch[0]=='*')
                   val = num1* num2;
               else if(ch[0]=='/')
                   val = num1/num2;
              
            //   System.out.println(num1 + "..." + val + "..." + num2);
               st1.push(String.valueOf(val));
           }
           else
               st1.push(tokens[i]);
           
          // System.out.println(st1);
           
       }
        return val;
    }
}