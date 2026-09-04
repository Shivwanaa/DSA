class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        if(stones.size()==2){
            return abs(stones[0]-stones[1]);
        }
        priority_queue<int>q;
        for(auto i:stones){
            q.push(i);
        }
        while(q.size()>=2){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            if(abs(a-b)!=0){
                q.push(abs(a-b));
            }
        }
        if(q.empty()){
            return 0;
        }
        return q.empty() ? 0 : q.top();
    }
};