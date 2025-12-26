class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            int cost=prices[i];
            maxProfit=max(maxProfit,prices[i]-mini);
            mini=min(mini,cost);
        }
        return maxProfit;       
    }
};