class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minn=1e9;
        int r=prices.size()-1;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minn){
                minn=prices[i];
            }
            else if(prices[i]-minn>ans){
                ans=prices[i]-minn;
            }
            
        }
        return ans;
    }
};