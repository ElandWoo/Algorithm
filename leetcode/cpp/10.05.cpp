class Solution {
public:
    int findString(vector<string>& words, string s) {
        // ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], 
        // s = "ball" 4
        int n = words.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (words[mid] == s) {
                return mid;
            } else if (words[mid] == ""){
                if (words[l] == s) {
                    return l;
                } else {
                    l++;
                }
            } else if (words[mid] < s) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;

    }
};