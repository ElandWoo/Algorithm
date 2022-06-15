class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (l == r) return nums[mid];
            if ((nums[(mid - 1 + n) % n] > nums[mid])) {
                return nums[mid];
            } else if (nums[mid] <= nums[r]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};