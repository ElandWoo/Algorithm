/*
runtime complexity
best :O(Logn), 
worst :O(n) :every elements is the same value, and is not target.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            // cut off duplicates
            if (nums[l] == nums[mid]) {
                l++;
                continue;
            }
            // left side sorted
            if (nums[mid] >= nums[l]) {
                if (nums[l] > target) {
                    l = mid + 1;
                    continue;
                }
                if (nums[mid] > target) {
                    r = mid - 1;
                    continue;
                }
                l = mid + 1;
                continue;
            }
            // right side sorted
            if (nums[r] < target) {
                r = mid - 1;
                continue;
            }
            if (nums[mid] < target) {
                l = mid + 1;
                continue;
            }
            r = mid - 1;
        }
        return false;
    }
};