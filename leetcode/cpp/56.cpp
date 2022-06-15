/*
Solution 1
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            int first = ans.back()[0];
            int second = ans.back()[1];
            if (second >= intervals[i][0]) {
                ans.pop_back();
                int tmp = max(intervals[i][1], second);
                ans.push_back({first, tmp});
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

/*
Solution 2
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [&] (const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
            });

        vector<vector<int>> ans;
        int start = -1, farthest = -1; // {start, farthest} is a new interval.
        for (vector<int>& interval : intervals) {
            int left = interval[0];
            int right = interval[1];
            if (left > farthest) {
                if (farthest != -1) ans.push_back({start, farthest});
                start = left;
                farthest = right;
            } else farthest = max(right, farthest);
        }
        ans.push_back({start, farthest});
        return ans;
    }
};

/*
Solution 3
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> actions;
        for (const vector<int>& interval : intervals) {
            actions.push_back({interval[0], 1});
            actions.push_back({interval[1] + 1, -1});
        }

        sort(actions.begin(), actions.end());

        vector<vector<int>> ans;
        int start = 0, covering = 0;
        for (const pair<int, int>& action : actions) {
            if (covering == 0) start = action.first;
            covering += action.second;
            if (covering == 0) 
                ans.push_back({start, action.first - 1});
        }

        return ans;
    }
};