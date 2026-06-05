class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<int>curr ;
        vector<vector<int>>result;
        solve(0 ,nums ,target ,curr,result);
        return result;

        
    }
    void solve(int i ,vector<int>&nums,int target ,vector<int>&curr ,vector<vector<int>>&result)
    {
        int n = nums.size();
        //if(i ==n)return
        if(target == 0){
            result.push_back(curr);
            return;
        }

        if(i==n)return ;

        if(target <0) return ;

        curr.push_back(nums[i]);
        solve(i ,nums ,target -nums[i],curr ,result);
        curr.pop_back();
        solve(i+1 ,nums , target ,curr ,result);
        
    }
};
