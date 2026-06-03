class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        int minbuy =prices[0];
        int maxprofit = 0;

        for(int sell : prices){
            maxprofit = max(maxprofit , sell -minbuy);
            minbuy =min(minbuy ,sell);
        }
        return maxprofit; 
    }
};
