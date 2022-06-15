#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    int nums[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    int pos = nums[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(pos - nums[i]);
    }
    cout << ans;
}