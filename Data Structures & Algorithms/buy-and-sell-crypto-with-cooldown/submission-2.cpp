class Solution {
public:
    int find(vector<int> &prices, int c, bool canBuy, vector<vector<int>> &dp){
        if(c >= prices.size()){
            return 0;
        }
        if(dp[c][canBuy] != -1) return dp[c][canBuy];
        if(canBuy){
            //buy
            int op1 = -prices[c] + find(prices, c+1, 0, dp);

            //ignore
            int op2 = find(prices, c+1, canBuy, dp);
            return dp[c][canBuy] = max(op1, op2);
        } else {
            //sell
            int op3 = prices[c] + find(prices, c+2, 1, dp);

            //ignore
            int op4 = find(prices, c+1, canBuy, dp);
            return dp[c][canBuy] = max(op3, op4);
        }
    }

    int maxProfit(vector<int>& prices) {
        bool canBuy{true};
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return find(prices, 0, canBuy, dp);
    }
};
