// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1; 
        long long r = n;
        long long mid = (l+(n-l))/2;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(isBadVersion(mid))
            {
                if(isBadVersion(mid -1))
                    r = mid - 1;
                else
                    return mid;
            }
            else
                l = mid + 1;
        }
        return -1;
    }
};