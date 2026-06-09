class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;
        backtrack(nums ,result ,curr ,0);
        return result;
        
    }
    void backtrack( vector<int>&nums , vector<vector<int>>&result , vector<int>curr ,int i){
        int n = nums.size();
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(int j = i ; j< n;j++){
            swap(nums[i] , nums[j]);
            curr.push_back(nums[i]);

            backtrack(nums, result ,curr ,i + 1);

            curr.pop_back();
            swap(nums[i] ,nums[j]);
            
        }
    }
};
