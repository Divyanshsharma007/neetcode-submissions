class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return solve(nums ,target, 0 , 0);        
    }
    int solve(vector<int>&nums , int target , int  i , int sum)
    {
        int n=nums.size();
        if(n == 0) return 0;
        if(i == n)return sum == target;

        return solve(nums ,target ,i+1 ,sum -nums[i]) + solve(nums , target ,i+1 , sum+ nums[i]);
    }
};
