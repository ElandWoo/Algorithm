class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                push(nums[i]);
            } else {
                push(nums[i]);
                ans.push_back(max());
                pop(nums[i - k + 1]);
            }
        }
        return ans;
    }

private:
    deque<int> window;

    void push(int n) {
        while (!window.empty() && window.back() < n)
            window.pop_back();
        window.push_back(n);
    }

    int max() {
        return window.front();
    }

    void pop(int n) {
        if (window.front() == n) window.pop_front();
    }
};