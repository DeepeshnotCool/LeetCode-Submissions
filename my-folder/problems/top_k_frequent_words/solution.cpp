class Solution {
public:
    
    static bool cmp(pair<string,int>& a,pair<string,int>& b)
    {
        return a.second > b.second;
    }
    
    vector<string> sort_by_value(map<string,int>& m, int k)
    {
        vector<pair<string,int>> v;
        for(auto it: m)
            v.push_back(it);
        sort(v.begin(), v.end(),cmp);
        for(auto it:v){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<string> ans;
        int prev = v[0].second;
        vector<string> result;
        for(auto it : v)
        {
            if(it.second != prev){
                vector<string> temp = ans;
                sort(temp.begin(), temp.end());
                ans.clear();
                for(auto it: temp){
                    result.push_back(it);
                }
                prev = it.second;
            }
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            result.push_back(it);
        }
        
        vector<string> final_result;
        for(auto it : result){
            if(k == 0)
                break;
            final_result.push_back(it);
            k--;
        }


        return final_result;
        
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        return sort_by_value(m,k);
    }
};