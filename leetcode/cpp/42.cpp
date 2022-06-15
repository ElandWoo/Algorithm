class Solution {
public:
    /*
    Solution1: 暴力解法，时间复杂度O（N^2）.
    */
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        // loop from idx 1th to idx n-1th,the edge contain no water.
        for (int i = 1; i < n - 1; ++i) {
            int l_max = 0, r_max = 0;
            // 1. find the max of the left nums;
            for (int j = 0; j <= i; ++j) {
                l_max = max(l_max, height[j]);
            }
            // 2. find the max of the right nums;
            for (int j = i; j < n; ++j) {
                r_max = max(r_max, height[j]);
            }
            // 3. update the ans.
            ans += min(r_max, l_max) - height[i];
        }
        return ans;
    }

    /*
    Solution2: 备忘录法，记录前缀后缀最大值。时间复杂度O(n),最佳；空间复杂度O(n),可优化。
    */
    int trap(vector<int>& height) {
        int n = height.size();
        // memento: l_max[i] means the height of highest bar before i. 
        int l_max[n];
        int r_max[n];
        // recorde the memento.
        l_max[0] = height[0]; r_max[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            l_max[i] = max(l_max[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            r_max[i] = max(r_max[i + 1], height[i]);
        }
        // get ans according to the memento.
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += min(r_max[i], l_max[i]) - height[i];
        }
        return ans;
    }

    /*
    Solution3: 双指针法，记录前缀后缀最大值。时间复杂度O(n), 空间复杂度O(1), 最佳。
    */
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int l_max = 0, r_max = 0;
        while (left < right) {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            if (l_max < r_max) {
                ans += l_max - height[left];
                left++;
            } else {
                ans += r_max - height[right];
                right--;
            }
        }
        return ans;
    }

    /*
    Solution4：单调栈。
    */
    int trap(vector<int>& height) {
        height.push_back(0); // help to clear the stack.
        int ans = 0;
        stack<Rect> bar;
        // 1. loop , and address each element;
        for (int h : height) {
            int accumulate_width = 0;
            // 2.while (Monotony is violated):
            while (!bar.empty() && h >= bar.top().height) {
                // 2.1 accumulate the width of water and get the bottom of the water,
                int bottom = bar.top().height;
                accumulate_width += bar.top().width;
                // 2.2 pop,
                bar.pop();
                // 2.3 if there is no bar, water will go off.
                if (bar.empty()) continue;
                // 2.4 update the ans;
                ans += (min(h, bar.top().height) - bottom) * accumulate_width;
            }
            // 3. push new element.(attentionly, the width of each bar is 1.)
            bar.push({h, accumulate_width + 1});
        }
        return ans;
    }
private:
    struct Rect {
        int height; 
        int width;
    };
};