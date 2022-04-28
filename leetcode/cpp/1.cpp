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
  
  /*
  we can delete a loop to make complexity O(n^2) to O(n)
  */
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
  
  /*
  and we can use unordered_map, tidy and fast.
  */
      vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // if target - nums[i] in m, just return the ans;
            // if not update the unordered_map.
            if (m.find(target - nums[i]) != m.end()) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }

  
  
  /*
  the same as last solution.
  */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // if target - nums[i] in m, just return the ans;
            // if not store one position into the second one's key.
            if (m.find(nums[i]) != m.end()) {
                return {m[nums[i]], i};
            }
            m[target - nums[i]] = i;
        }
        return {};
    }
};
