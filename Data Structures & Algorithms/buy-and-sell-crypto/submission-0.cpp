class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprice=INT_MIN,maxprofit=INT_MIN;
        for(int i = prices.size()-1;i>=0;i--){
            maxprice=max(maxprice,prices[i]);
            maxprofit=max(maxprofit,maxprice-prices[i]);
        }
        return maxprofit;
    }
};
