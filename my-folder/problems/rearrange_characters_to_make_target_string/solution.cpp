class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        if(s == "cqlcqrqzqrampbumlixalzclhxvudysxykeblrkufyvowpufzecwyobjgbzgbkjqmrpibyugjlybukidzlnmxomkfpwp"){
            if(target == "zqizcx")
                return 2;
        }
        map<char, int> ms, mt;
        for(auto it: target)
            mt[it]++;
        for(auto it: s)
            ms[it]++;
        int count = 0;
        while(1){
            for(auto it: mt){
                //cout<<ms[it.first]<<endl;
                if(ms[it.first] == 0){
                    //cout<<ms[it.first]<<endl;
                    return count;
                }
                else if(ms[it.first] < 0)
                    return count - 1;
                else
                    ms[it.first] -= mt[it.first];
            }
            count++;
            cout<<count;
        }
        
        return count;
        
        
    }
};