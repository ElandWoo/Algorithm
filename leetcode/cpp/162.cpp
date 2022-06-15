class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                l = mid + 1;
            } else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                }
                r = mid - 1;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};