class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {

          int n = nums.size();

        vector<int> even(n + 1, n);
        vector<int> odd(n + 1, n);

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0)
                even[i] = i;
            else
                even[i] = even[i + 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2)
                odd[i] = i;
            else
                odd[i] = odd[i + 1];
        }

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            long long same = 0;
            long long diff = 0;

            int j, k;

            if (nums[i] % 2 == 0) {
                j = even[i + 1];
                k = odd[i + 1];
            } else {
                j = odd[i + 1];
                k = even[i + 1];
            }

            if (j < n)
                same = nums[j] + dp[j];

            if (k < n)
                diff = nums[k] - x + dp[k];

            dp[i] = max(same, diff);
        }

        return nums[0] + dp[0];
        
    }
};