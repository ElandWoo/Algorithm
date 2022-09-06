class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> h;
        for (int num : nums) {
            if (h.find(num) != h.end()) {
                return num;
            }
            h.insert(num);
        }
        return -1;
    }
};