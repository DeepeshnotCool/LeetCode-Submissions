class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        int count = 0;
        int arr[61];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < time.size(); i++){
            int temp = time[i]%60;
            if(!temp){
                count += arr[temp];
            } else {
                count += arr[60 - temp];
            }        
            arr[temp]++;
        }
        return count;
        // int count = 0;
        // for(int i = 0; i < time.size(); i++){
        //     int temp = time[i];
        //     for(int j = i+1; j < time.size(); j++){
        //         if((time[i] + time[j]) % 60 == 0)
        //             count++;
        //     }
        // }
        return count;
    }
};