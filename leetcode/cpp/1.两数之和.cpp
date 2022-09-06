/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> heap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (heap.find(target - nums[i]) == heap.end())
            {
                heap[nums[i]] = i;
                continue;
            }
            result.push_back(heap[target - nums[i]]);
            result.push_back(i);
            break;
        }
        return result;
    }
};
// @lc code=end

