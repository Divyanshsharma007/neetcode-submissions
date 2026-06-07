class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)return 0;
        vector<vector<int>>dp(n+1 , vector<int>(2,-1));
        return solve(prices ,0, 0 ,dp);

        
    }
    int solve(vector<int>& prices , int buy ,int ind , vector<vector<int>>&dp){
        int n= prices.size();
        if(n == 0)return 0;
        int profit = 0;
        if(ind>=n)return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy == 0){
            int buykaro = -prices[ind] + solve(prices ,1 ,ind + 1 ,dp);
            int buymatkaro = solve(prices ,0 , ind + 1 ,dp);
            profit =max(buykaro ,buymatkaro);
        }
        if(buy == 1){
            int sellkar = + prices[ind] + solve(prices , 0 ,ind +2 ,dp);
            int sellmatkaro = solve(prices ,1 ,ind+1 ,dp);
            profit = max(sellkar ,sellmatkaro);
        }

        return dp[ind][buy] = profit;
    }
};
