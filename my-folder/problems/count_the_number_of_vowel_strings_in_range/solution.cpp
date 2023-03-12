class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++){
            string temp = words[i];
            int n = temp.size();
            if(temp.size() > 0 && (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u') && (temp[n-1] == 'a' || temp[n-1] == 'e' || temp[n-1] == 'i' || temp[n-1] == 'o' || temp[n-1] == 'u'))
                count++;
        }
        return count;
    }
};