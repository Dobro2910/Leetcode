class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else if (nums.size() == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }

        int maxMoney = 0;
        vector<int> dp(nums.size());

        // max at house 1;
        dp[0] = nums[0];
        // max at house 2;
        dp[1] = nums[1];
        // max at house 3;
        dp[2] = nums[0] + nums[2];

        for (int i = 3; i < nums.size(); ++i) {
            dp[i] = max({dp[i - 1], dp[i - 2] + nums[i], dp[i - 3] + nums[i]});
            if (dp[i] > maxMoney) {
                maxMoney = dp[i];
            }
        }

        return maxMoney;
    }
};