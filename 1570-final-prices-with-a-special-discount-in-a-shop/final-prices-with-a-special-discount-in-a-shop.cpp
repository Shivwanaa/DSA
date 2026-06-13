class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans=prices;
        stack<int>s;
        for(int i=0;i<prices.size();i++){
            while(!s.empty() && prices[s.top()]>=prices[i]){
                ans[s.top()]-=prices[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};