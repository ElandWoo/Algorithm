/*
154. Find Minimum in Rotated Sorted Array II
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            // skip the same element, this would cause the O(n) run-time complexity. 
            while (r - l > 1 && nums[r] == nums[l]) {
                l++;
            }
            int mid = l + ((r - l) >> 1);
            if (nums[l] == nums[r]) return nums[l];
            if ((mid != 0 && nums[mid] < nums[mid - 1]) || (mid == 0 && nums[mid] <= nums[r])) {
                return nums[mid];
            }
            // left side sorted
            if (nums[mid] > nums[r]) {
                l = mid + 1;
                continue;
            }
            // right side sorted
            r = mid - 1;
        }
        return -1;
    }
};