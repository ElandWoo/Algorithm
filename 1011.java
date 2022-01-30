class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0, right = 1;
        for (int weight : weights) {
            left = Math.max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (validate(weights, mid, days)) {
                right = mid; 
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
    // 定义： 当运载能力为x时， 判断是否能在days天运完
    Boolean validate(int[] weights, int x, int days) {
        int day= 0;
        for (int i = 0; i < weights.length; ) {
            //尽可能的多装货物
            int cap = x;
            while (i < weights.length) {
                //余下容量再装不下货物
                if (cap < weights[i]) break;
                else cap -= weights[i];
                i++;
            }
            day++;
        }
        return day <= days;
    }
}
