class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1)return nums[0];
        vector<int>d1(n,-1);
        vector<int>d2(n,-1);
        return max(solve(nums ,0 , n-2 ,d1), solve(nums,1 ,n-1,d2));
        
    }

    int solve(vector<int>&nums , int i ,int end ,vector<int>&dp)
    {
        int n = nums.size();
        if(i>end)return 0;

        if(dp[i]!=-1) return dp[i];
        
        if(n==1)return nums[0];
        if(nums.empty())return  0;

        int rob = nums[i] + solve(nums ,i+2 ,end ,dp);
        int notrob = solve(nums ,i+1 ,end , dp);
        return dp[i]=max(rob,notrob);
    }
};
