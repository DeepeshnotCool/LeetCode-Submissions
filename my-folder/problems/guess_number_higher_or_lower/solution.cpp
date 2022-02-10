/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        long long r = n;
        while(l <= r)
        {
            long long mid = l+(r-l)/2;
            int target = guess(mid);
            //cout<<target;
            if(target == 0)
            {
                return mid;
            }
            if(target == 1)
                l = mid+1;
            else if(target == -1)
                r = mid-1;
        }
        return -1;
    }
};