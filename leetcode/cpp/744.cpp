class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (letters[mid] > target) {
                if (mid == 0 || letters[mid - 1] <= target) {
                    return letters[mid];
                }
                r = mid - 1;
            }
            if (letters[mid] <= target) {
                l = mid + 1;
            }
        }
        return letters[0];
    }
};