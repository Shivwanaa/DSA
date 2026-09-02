class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>q;
        unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            q.push({i.first,i.second});
        }
        string ans="";
        while(q.size()){
            auto[ch,fr]=q.top();
            q.pop();
            int fre=min(fr,repeatLimit);
            while(fre){
                ans+=ch;
                fre--;
            }
            if(!q.empty() && fr-min(fr,repeatLimit)>0){
                auto [ch1,fr1]=q.top();
                q.pop();
                ans+=ch1;
                if(fr1-1>0)
                q.push({ch1,fr1-1});
                q.push({ch,fr-min(fr,repeatLimit)});
            }
        }
        return ans;
    }
};