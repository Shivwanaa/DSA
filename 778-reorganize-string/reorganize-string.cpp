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
        string ans;
        while(q.size()){
            auto[freq1,ch1]=q.top();
            q.pop();
            ans=ans+ch1;
            if(q.empty() && freq1-1>0){
                // cout<<ans;
                return "";
            }
            if(q.empty()){
                return ans;
            }
            auto[freq2,ch2]=q.top();
            q.pop();
            ans=ans+ch2;

            if(freq1-1>0)
            q.push({freq1-1,ch1});
            if(freq2-1>0)
            q.push({freq2-1,ch2});
        }
        return ans;
    }
};