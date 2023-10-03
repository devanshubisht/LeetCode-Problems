class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0]; 
        int result = 0;

        for (int i = 0 ; i < prices.size() ; i++) {
            minP = min(prices[i], minP);
            result = max(result, prices[i]-minP);
        }
        return result;
    }
};