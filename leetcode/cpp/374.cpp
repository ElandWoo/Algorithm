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
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (guess(mid) == 0) {
                return mid;
            }
            if (guess(mid) == -1) {
                r = mid - 1;
                continue;
            }
            if (guess(mid)) {
                l = mid + 1;
                continue;
            }
        }
        return l;
    }
};