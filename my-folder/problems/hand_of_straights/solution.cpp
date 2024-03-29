class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for(auto it: hand){
            m[it]++;
        }
        map<int, int> :: iterator it = m.begin();
        while(it != m.end()){
            if(it -> second > 0){
                for(int i = 0; i < groupSize; i++){
                    if(m[it -> first + i] > 0){
                        m[it -> first + i]--;
                    } else{
                        return false;
                    }
                }
            } else{
            it++;
            }
        }
        return true;
    }
};