class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>q;
        unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            q.push({i.second,i.first});
        }
        string ans="";
        while(q.size()){
            auto [freq,let]=q.top();
            q.pop();
            if(ans.size() && let==ans.back()){
                if(!q.size()){
                    return "";
                }
                auto [f1,n]=q.top();
                q.pop();
                ans=ans+n;
                f1--;
                if(f1){
                    q.push({f1,n});
                }
                q.push({freq,let});
            }
            else{
                ans=ans+let;
                freq--;
                if(freq){
                    q.push({freq,let});
                }
            }
        }
        return ans;
    }
};