// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=10005, ans=0;
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};