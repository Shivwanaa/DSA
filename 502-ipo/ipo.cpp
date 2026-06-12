class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //maximize capital 
        //max_heap=profits and min_heap capital
        priority_queue<int>q;
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        int j=0;
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++){
            while(j<v.size() && w-v[j].first>=0){
                q.push(v[j++].second);
            }
            if(q.empty()){
                break;
            }
            w=w+q.top();
            q.pop();
        }
        return w;
    }
};