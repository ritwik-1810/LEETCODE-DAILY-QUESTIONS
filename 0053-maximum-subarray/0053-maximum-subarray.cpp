class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& memo) {
    // Base case
    if (i == 0)
        return memo[i] = nums[i];

    // If already computed
    if (memo[i] != INT_MIN)
        return memo[i];

    // Recurrence:
    // Max subarray ending at i is either:
    // 1. Start new subarray at i
    // 2. Extend previous subarray
    int extend = solve(i - 1, nums, memo) + nums[i];
    int startNew = nums[i];

    memo[i] = max(startNew, extend);
    return memo[i];
}
    int maxSubArray(vector<int>& nums) {

         int n = nums.size();
    vector<int> memo(n, INT_MIN);

    int ans = INT_MIN;

    // Evaluate dp[i] for all i
    for (int i = 0; i < n; i++) {
        ans = max(ans, solve(i, nums, memo));
    }

    return ans;
        
    }
};