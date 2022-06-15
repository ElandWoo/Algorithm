/*
Solution1: 计数排序
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);
        for (int val : arr1) count[val]++;

        vector<int> ans;
        for (int val : arr2) {
            while (count[val] > 0) {
                ans.push_back(val);
                count[val]--;
            }
        }

        for (int i = 0; i <= 1000; ++i) {
            while (count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }

        return ans;
    }
};

/*
Solution2 改造库函数
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> arr2Order;
        for (int i = 0; i < arr2.size(); ++i) arr2Order[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            int xpos = arr2Order.find(x) == arr2Order.end() ? arr2.size() : arr2Order[x];
            int ypos = arr2Order.find(y) == arr2Order.end() ? arr2.size() : arr2Order[y];
            return xpos < ypos || xpos == ypos && x < y;
        });
        return arr1;
    }
};