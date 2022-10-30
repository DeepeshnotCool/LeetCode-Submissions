class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long> m;
        map<string, vector<long long>> mi;
        for(int i = 0; i < creators.size(); i++){
            m[creators[i]] +=  views[i];
            mi[creators[i]].push_back(i);
        }
        vector<string> v;
        long long maxi = -1;
        for(auto it: m){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        
        for(auto it: m){
            if(it.second == maxi)
                v.push_back(it.first);
        }
        
        
        
        vector<vector<string>> ans;
        for(auto it: v){
            cout<<it<<endl;
            vector<string> temp;
            int maxviewcount = INT_MIN;
            for(auto it1: mi[it]){
                if(views[it1] > maxviewcount){
                        maxviewcount = views[it1];
                    }
            }
            
            for(auto it1: mi[it]){
                cout<<it1<<" ";
                int index = it1;
                if(views[index] == maxviewcount)
                    temp.push_back(ids[index]);
            }
            if(!temp.empty()){
                sort(temp.begin(), temp.end());
                vector<string> tempans;
                tempans.push_back(it);
                tempans.push_back(temp[0]);
                ans.push_back(tempans);
            }
        }
        return ans;
        
    }
};