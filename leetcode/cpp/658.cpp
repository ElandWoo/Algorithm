// Author : Eland Woo
// Date   : 2022.06.16
// time complexity :O(logn + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (x - arr[mid] <= arr[mid + k] - x) {
                r = mid;
                continue;
            }
            l = mid + 1;
        }

        vector<int> ans;
        for (int i = l; i < l + k; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
