class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        set<pair<int, int>> st;
        int n=costs.size();
        long long ans=0;
        if(candidates * 2 >= n){
            for(int i=0; i < n; i++){
                st.insert({costs[i],i});
                
            }
            for(int i=0; i < k; i++){
                if(st.size() == 0)
                    return ans;
                auto it = *(st.begin());
                ans += it.first;
                st.erase(it);
            }
            return ans;
        }
        int l = 0, r = n-1;    
        for( l = 0; l < candidates; l++){
            st.insert({costs[l], l});
        }
        for(r = n-1; r >= n-candidates; r--){
            st.insert({costs[r],r});
        }
        l--;
        r++;
        for(int i = 0; i < k; i++){
            auto it = *(st.begin());
            ans += it.first;
            int x = it.second;
            st.erase(it);
           
            if(x <= l){
                l++;
                if(l < r){
                    st.insert({costs[l],l});
                }
            }
            else if(x >= r){
                r--;
                if(l < r){
                   st.insert({costs[r],r}); 
                }
            }
        }
        return ans;
    }
};