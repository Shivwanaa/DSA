class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        auto comp=[](pair<char,int>a,pair<char,int>b){
            return a.second<b.second;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)>q(comp);
        if(a>0)
        q.push({'a',a});
        if(b>0)
        q.push({'b',b});
        if(c>0)
        q.push({'c',c});
        while(q.size()){
            auto [ch,f]=q.top();
            q.pop();
            if(ans.size()>=2 && ch==ans[ans.size()-1] && ans[ans.size()-1]==ans[ans.size()-2 ]){
                if(q.empty()){
                break;
               }
                auto [c1,f1]=q.top();
                q.pop();
                ans=ans+c1;
                if(f1-1>0){
                    q.push({c1,f1-1});
                }
            }
            else{
                ans=ans+ch;
                f=f-1;
            }
            if(f>0){
                q.push({ch,f});
            }
        }
        return ans;
    }
};