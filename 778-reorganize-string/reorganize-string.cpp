class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        auto comp=[](pair<char,int>a,pair<char,int>b){
            return a.second<b.second;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)>q(comp);
        for(auto i:m){
            q.push({i.first,i.second});
        }
        string ans="";
        while(q.size()){
            auto[c,f]=q.top();
            q.pop();
            if(ans.size() && c==ans[ans.size()-1]){
                if(q.empty()){
                    return "";
                }
                auto [c1,f1]=q.top();
                q.pop();
                ans=ans+c1;
                if(f1-1>0){
                    q.push({c1,f1-1});
                }
            }
            else{
                ans=ans+c;
                f--;
            }
            if(f){
                q.push({c,f});
            }
        }

        if(ans.size()==s.size())
        return ans;
        return "";
    }
};