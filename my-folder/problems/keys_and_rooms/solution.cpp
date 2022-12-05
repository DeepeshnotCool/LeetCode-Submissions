class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                visited[front] = 1;
                for(auto it: rooms[front]){
                    if(!visited[it])
                        q.push(it);
                }
            }
        }

        int count = 0;
        for(auto it: visited){
            if(it)
                count++;
        }
        return count == n;
    }
};