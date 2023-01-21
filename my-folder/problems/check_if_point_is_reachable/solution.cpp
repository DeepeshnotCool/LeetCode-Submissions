class Solution {
public:
    
    bool isReachable(int targetX, int targetY) {
        while(true){
             if(targetX == targetY){
                 if(targetX == 1 || targetY == 1)
                     return true;
                 int count1 = 0, count2 =0;
                 for(int i = 0; i < 31; i++){
                     if((1<<i)&targetX)
                         count1++;
                     if((1<<i)&targetY)
                         count2++;
                 }
                 if(count1 == 1 && count2 == 1)
                     return true;
                 return false;
             } else if(targetX > targetY){
                 targetX -= targetY;
             } else{
                 targetY -= targetX;
             }
         }
        return false;
        
    }
};