class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> returnArray(n, 1);

        // Step 1: Build prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            returnArray[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Multiply by suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            returnArray[i] *= suffix;
            suffix *= nums[i];
        }

        return returnArray;
    }
};
