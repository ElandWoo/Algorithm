class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, u = nums.size() - 1;
        qsort(nums, l, u);
        isort(nums);
        return nums;
    }

    void qsort(vector<int>& nums, int l, int u) {
        // base case, if the num of elements less than cutoff, use insertSort.
        if(u - l < 10) return;
        // 1.pick pivot randomly.
        swap(nums[l], nums[rand() % (u - l + 1) + l]);
        int pivot = nums[l];
        // 2.partiton
        int i = l, j = u + 1;
        while (i <= j) {
            do i++; while (i < u && nums[i] < pivot);
            do j--; while (nums[j] > pivot);
            if (i >= j) break;
            // swap() better be unfold in the inline func.
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        swap(nums[j], nums[l]);
        // 3.recursion
        qsort(nums, l, j - 1);
        qsort(nums, j + 1, u);
    }

    void isort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int value = nums[i];
            int j = i;
            for (; j > 0 && nums[j - 1] > value; --j) {
                nums[j] = nums[j - 1];
            }
            nums[j] = value;
        }
    }
};