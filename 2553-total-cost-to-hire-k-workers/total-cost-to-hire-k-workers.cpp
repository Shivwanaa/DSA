class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<>>q1,q2;
        long long ans=0;
        for(int i=0;i<candidates;i++){
            q1.push(costs[i]);
        }
        int n = costs.size();
        int startRight = max(candidates, n - candidates);
        for(int i=startRight;i<costs.size();i++){
            q2.push(costs[i]);
        }
        int nstart=candidates;
        int nend=costs.size() - 1 - candidates;
        for(int i=0;i<k;i++){
            if(q2.empty() || (!q1.empty() && q1.top() <= q2.top())){
                ans=ans+q1.top();
                q1.pop();
                if(nstart<=nend){
                q1.push(costs[nstart]);
                nstart++;
                }
            }
            else{
                ans=ans+q2.top();
                q2.pop();
                if(nstart<=nend){
                q2.push(costs[nend]);
                nend--;
                }
            }
            
        }
        return ans;
    }
};