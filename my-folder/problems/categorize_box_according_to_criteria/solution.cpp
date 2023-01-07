class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = length*1LL*width*1LL*height;
        
        if(length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9){
            if(mass >= 100){
                return "Both";
            } else{
                return "Bulky";
            }
        } else{
            if(mass >= 100){
                return "Heavy";
            } else{
                return "Neither";
            }
        }
        return "";
    }
};