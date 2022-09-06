class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (consumeInTime(piles, mid) <= h) {
                if (consumeInTime(piles, mid - 1) > h) {
                    return mid;
                }
                r = mid - 1;
                continue;
            }
            l = mid + 1;
        }
        return -1;
    }

    int consumeInTime(vector<int> piles, int speed) {
        if (speed == 0) return 1e9;
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }
        return hours;
    }
};
