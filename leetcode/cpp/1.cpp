// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Eland Woo
// Date   : 2022.04.28


class Solution {
public:
  
  /*
  time complexity O(n^2), not good.
  */
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        int tmp = target - nums[i];
        for (int j = i + 1; j < n; j++)
            if (nums[j] == tmp) {
                return {i,j};
            }
        }
    return {};
    }
  
    vector<int> twoSum(vector<int>& nums, int target) {
        // store nums[i] ans i in case of sort
        vector<pair<int, int>> array;
        for (int i = 0; i < nums.size(); i++) {
            array.push_back({nums[i], i});
        }
        sort(array.begin(), array.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            // if nums[i] + nums[j] > target , j--
            // loop untill nums[i] + nums[j] <= target
            while (array[i].first > target - array[j].first) j--;
            // if nums[i] + nums[j] = target, return ans
            // else i++, redo all above
            if (array[i].first == target - array[j].first)
                return {array[i].second, array[j].second};
            i++;
        }
        return {};
    }
};
