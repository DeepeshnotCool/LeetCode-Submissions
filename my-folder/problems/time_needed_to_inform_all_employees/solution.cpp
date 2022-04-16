class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            if(manager[i] != -1)
                m[manager[i]].push_back(i);  
        }
        queue<pair<int,int>> q;
        q.push({headID, 0});
        int maxi = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front().first;
                auto intime = q.front().second;
                q.pop();
                int finalTime = informTime[front] + intime;
                maxi = max(maxi, finalTime);
                //cout<<front<<" -> ";
            
                for(auto it: m[front]){
                    //cout<<it<<endl;
                    q.push({it, finalTime});
                }
                //cout<<endl;
            }
            //cout<<maxi<<endl;
        }
//         for(auto it: m){
//             int maxi = INT_MIN;
//             for(auto it1: it.second){
//                 cout<<it.first<<" -> "<<it1<<endl;
                
//                 maxi = max(maxi,it1);
//             }
//             sum += maxi;
//         }
        return maxi;
     
    }
};