class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 1, r = (num >> 1) + 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            long long sqrt = (long long)mid * mid;
            if (sqrt == num) {
                return mid;
            } else if (sqrt < num){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};