class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        // int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
        // int dx[9] = {0,0,-1,-1,1,1,0,-1,1};
        // int dy[9] = {0,-1,0,-1,-1,0,1,1,1};
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(img2[i][j]){
        //             bool flag = false;
        //             for(int k = 0; k < 9; k++){
        //                 int prevx = i + dx[k];
        //                 int prevy = j + dy[k];
        //                 if(prevx >= 0 && prevx < n && prevy >= 0 && prevy < n && img1[prevx][prevy]){
        //                     switch(k){
        //                         case 0: count1++;
        //                                 break;
        //                         case 1: count2++;
        //                                 break;
        //                         case 2: count3++;
        //                                 break;
        //                         case 3: count4++;
        //                                 break;
        //                         case 4: count5++;
        //                                 break;
        //                         case 5: count6++;
        //                                 break;
        //                         case 6: count7++;
        //                                 break;
        //                         case 7: count8++;
        //                                 break;
        //                         case 8: count9++;
        //                                 break;
        //                     }
        //                     flag = true;
        //                 }
        //                 if(!flag){
        //                     cout<<"here"<<endl;
        //                     int m = 1;
        //                     prevx = i + dx[k];
        //                     prevy = j + dy[k];
        //                     while(prevx >= 0 && prevx < n && prevy >= 0 && prevy < n){
        //                         prevx = i + m * dx[k];
        //                         prevy = j + m * dy[k];
        //                         m++;
        //                         if(img1[prevx][prevy]){
        //                             flag = true;
        //                             break;
        //                         }
        //                     }
        //                     if(flag){
        //                         switch(k){
        //                         case 0: count1++;
        //                                 break;
        //                         case 1: count2++;
        //                                 break;
        //                         case 2: count3++;
        //                                 break;
        //                         case 3: count4++;
        //                                 break;
        //                         case 4: count5++;
        //                                 break;
        //                         case 5: count6++;
        //                                 break;
        //                         case 6: count7++;
        //                                 break;
        //                         case 7: count8++;
        //                                 break;
        //                         case 8: count9++;
        //                                 break;
        //                         }   
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<int> v{count1, count2, count3, count4, count5, count6, count7, count8, count9};
        // int maxi = *max_element(v.begin(), v.end());
        // return maxi;
        vector<pair<int, int>> v1, v2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j]){
                    v1.push_back({i,j});
                }
                if(img2[i][j]){
                    v2.push_back({i,j});
                }
            }
        }

        map<pair<int, int>, int> m;
        int maxi = 0;
        for(auto it1: v1){
            for(auto it2: v2){
                int prevx = it1.first - it2.first;
                int prevy = it1.second - it2.second;
                m[{prevx, prevy}]++;
                maxi = max(maxi, m[{prevx, prevy}]);
            }
        }
        return maxi;
    }
};