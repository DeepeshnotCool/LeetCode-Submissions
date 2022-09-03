class Solution {
public:
    
    string helper(int decimal, int base){
        if(decimal == 0)
            return "0";
        char nums[] = "0123456789ABCDEF";
        string result = "";
        do{
            result.push_back(nums[decimal%base]);
            decimal /= base;
        }while(decimal != 0);
        
        return string(result.rbegin(), result.rend());
    }
    
    bool isPalindrome(string str){
        string s = str;
        reverse(s.begin(), s.end());
        
        if(s == str){
            return true;
        }
        else
            return false;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n-2; i++){
            if(!isPalindrome(helper(n,i))){
                return false; 
            }
        }
        return true;
    }
};