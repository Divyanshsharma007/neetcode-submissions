class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int>curr;
        vector<vector<int>>result;
        sort(candidates.begin(), candidates.end());
        solve(0 ,candidates ,target ,curr ,result);
        return result;        
        
    }
    void solve(int ind , vector<int>&candidates , int target , vector<int>&curr ,vector<vector<int>>&result){
        
        if (target == 0){
            result.push_back(curr);
            return;
        }      

        int n =candidates.size();

         //if(ind==n)return ;
         //if(target <0)return

        for(int i =ind ;i<n;i++){

            if(i>ind && candidates[i]==candidates[i-1]) continue;


            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            solve(i+1,candidates ,target-candidates[i] ,curr ,result);
            curr.pop_back();
           // solve(i+1 , candidates , target, curr ,result);

        }
    }
};
