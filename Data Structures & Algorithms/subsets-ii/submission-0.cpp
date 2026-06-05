class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>result;
        solve(0,nums,result ,curr);
        return result;
        
    }
    void solve(int indx ,vector<int>&nums ,vector<vector<int>>&result ,vector<int>&curr)
    {
        int n = nums.size();
        //if(indx ==n)result.push_back(curr);

        result.push_back(curr);
        sort(nums.begin(),nums.end());
        for(int i =indx ;i<n ;i++)
        {
            if(nums[i]==nums[i-1] && i>indx)continue ;
            curr.push_back(nums[i]);
            solve(i+1 ,nums ,result ,curr);
            curr.pop_back();            
        }
    }
};
