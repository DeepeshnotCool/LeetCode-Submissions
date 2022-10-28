class RangeFreqQuery {
public:
    map<int, vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // int count = 0;
        // for(int i = left; i <= right; i++){
        //     if(v[i] == value)
        //         count++;
        // }
        // return count;
        return upper_bound(begin(m[value]), end(m[value]), right) - lower_bound(begin(m[value]), end(m[value]), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */