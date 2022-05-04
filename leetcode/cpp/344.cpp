class Solution {
public:
    void reverseString1(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }

    void reverseString2(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

};
