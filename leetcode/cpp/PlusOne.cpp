/*
66.加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
时间复杂度最好为O(1),最坏为O(n);空间复杂度最好为O(1),最坏为O(n).
*/

class Solution {
public:
    //递归中计数器
    int count = 0;
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-count;
        //没有9，该数位直接加1
        if (digits[n-1] != 9) {
            digits[n-1] += 1;
            return digits;
        }
        //如果有9，该数位设置为0，高数位加1
        digits[n-1] = 0;
        //如果遇到最高数位为9，重新申请空间
        if (n == 1) {
            vector<int> tmp(digits.size()+1);
            tmp[0] = 1;
            for (int i = 0; i<digits.size();i++) {
                tmp[i+1] = digits[i];
            }
            return tmp;
        }
        count ++;
        return plusOne(digits);
    }
};
