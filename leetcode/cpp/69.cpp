class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = (x >> 1) + 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                if ((mid + 1) <= x / (mid + 1)) {
                    l = mid + 1;
                } else {
                    return mid;
                }
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};