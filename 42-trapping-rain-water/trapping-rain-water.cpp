class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n, 0);
        vector<int>r(n, 0);
        for (int i=1; i<n; i++) {
            l[i] = max(l[i-1], nums[i-1]);
        }
        for (int i=n-2; i >= 0; i--) {
            r[i] = max(r[i + 1], nums[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int water = min(l[i], r[i]) - nums[i];

            if (water > 0) {
                ans += water;
            }
        }
        return ans;
    }
};