class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        // egs : 123 129 199 99
        for (int i = n - 1; i >= 0; i--) {
            if (carry) {
                if (digits[i] < 9) {
                    digits[i]++;
                    carry = 0;
                }
                else digits[i] = 0;
            }
        }

        if (carry) {
            digits.push_back(0);
            for (int i = 0; i < n; i++) {
                digits[i + 1] = digits[i];
            }
            digits[0] = 1;
        }

        return digits;
    }


	/*
	solution2递归
	*/
    int count = 0;
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - count;
        //没有9，直接加一
        if(digits[n - 1] != 9) {
            digits[n-1] += 1;
            return digits;
        }

        digits[n - 1] = 0;  
        if(n == 1) {
            vector<int> tmp(digits.size() + 1);
            tmp[0] = 1;
            for (int i = 0; i < digits.size(); i++) {
                tmp[i + 1] = digits[i];
            }
            return tmp;
        }
        count++;
        return plusOne(digits);
    }
};
