class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = nums.size();
        while (i < j) {
            do i++; while(i < j && nums[i] == 0);
            do j--; while(i < j && nums[j] != 0);
            if (i >= j) break;
            nums[j] = nums[i];
            nums[i] = 0;
       }
       i = -1; j = nums.size();
       while (i < j) {
            do i++; while(i < j && nums[i] != 2);
            do j--; while(i < j && nums[j] == 2);
            if (i >= j) break;
            nums[i] = nums[j];
            nums[j] = 2;
       }
       for (int nu : nums) cout<< nu;
       cout<< endl;
    }
};