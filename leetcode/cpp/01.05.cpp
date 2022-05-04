class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        // 1 if one string is 2 longer or short than the other. there's no solution;
        if (m - n > 1 || n - m > 1) return false;
        // 2 if two strings has the same length:
        // 2.1 they are totally same , just need 0 edits;
        // 2.2 they has one difference in somewhere ,just need 1 edit--replace.
        if (m == n) {
            int dif = 0;
            for (int i = 0; i < n; i++) {
                if (first[i] != second[i]) {
                    dif++;
                    // if (dif > 1) return false;
                }
            }
            return dif <= 1;
        }
        // 3 if one string is 1 longer or short than the other:
        // 2.1 if there is one diff and m < n,just need an insert in first--one edit;
        // 2.2 if there is one diff and m > n,just need a delete in first--one edit;
        // else there is more diffs, need not only one edit.
        int i = 0, j = 0, dif = 0;
        while (i < m && j < n) {
            if (first[i] == second[j]) {
                i++;
                j++;
            } else {
                dif++;
                if (n < m) i++;
                else j++;
            }
        }
        return dif <= 1;
    }
};
