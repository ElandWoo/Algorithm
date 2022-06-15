class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // attentionly, help to clear the stack.
        int ans = 0;
        stack<Rect> bar;
        // 1.loop address ench element in vector heights;
        for (int h : heights) {
            int accumulated_width = 0;
            // 2.while (monotony is violated):
            while (!bar.empty() && h <= bar.top().height) {
                // 2.1 accumulate the width of bar,
                accumulated_width += bar.top().width;
                // 2.2 update the ans,
                ans = max(accumulated_width * bar.top().height, ans);
                // 2.3 pop the top of the stack bar;
                bar.pop();
            }
            // 3. push new element(attentionly, each the width of each bar is 1).
            bar.push({h, accumulated_width + 1});
        }
        return ans;
    }
private:
    // rectangle with its height ans width.
    struct Rect {
        int height;
        int width;
    };
};