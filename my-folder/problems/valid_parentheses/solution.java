class Solution {
    public boolean isValid(String s) {
     Stack<Character> st = new Stack<>();
     for(char i : s.toCharArray()){
        if(i == '(' || i == '{' || i == '[')
            st.push(i);
         else{
             if(st.empty())
                 return false;
                 
             if(i == ')'){
                 if(st.peek() == '(')
                     st.pop();
                 else
                     return false;
            }
             else if(i == '}'){
                 if(st.peek() == '{')
                     st.pop();
                 else
                     return false;
            }
             else if(i == ']'){
                 if(st.peek() == '[')
                     st.pop();
                 else
                     return false;
             }
        }
     }
        
        if(st.empty())
            return true;
        else
            return false;     
    }
}