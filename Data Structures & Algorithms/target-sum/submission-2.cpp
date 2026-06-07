class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(target > totalSum)
            return 0;

        if((totalSum + target) % 2)
            return 0;

        int reqSum = (totalSum + target) / 2;

        vector<int> dp(reqSum + 1, 0);
        dp[0] = 1;

        for(int num : nums)
        {
            for(int t = reqSum; t >= num; t--)
            {
                dp[t] += dp[t - num];
            }
        }

        return dp[reqSum];
    }   
};

/* int solve(vector<int>&nums , int target , int  i , int sum)
    {
        int n=nums.size();
        if(n == 0) return 0;
        if(i == n)return sum==target;

        return solve(nums ,target ,i+1 ,sum -nums[i]) + solve(nums , target ,i+1 , sum+ nums[i]);
    }
    */
