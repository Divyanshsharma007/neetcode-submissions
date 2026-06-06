class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(coins.empty())return 0;
        if(amount==0)return 0;
        vector<int>dp(amount +1 ,amount +1);
        dp[0]=0;
        for(int coin :coins){
            for(int target = coin; target<=amount ;target++){
                dp[target ]= min(dp[target] , dp[target-coin] +1);
            }
        }
        if (dp[amount]==amount+1) return -1;
        else return dp[amount];
        
    }
};
