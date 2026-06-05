class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;
        solve(0 ,nums ,curr ,result);
        return result;
                
    }
    void solve(int index , vector<int>&nums ,vector<int>&curr ,vector<vector<int>>&result){
        result.push_back(curr);
        int n =nums.size();
        
        for(int i=index ;i < n;i++){
            curr.push_back(nums[i]);
            solve(i+1 ,nums ,curr ,result);
            curr.pop_back();            
        }
    }
};
