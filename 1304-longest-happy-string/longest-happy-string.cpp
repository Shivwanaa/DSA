class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>q;
        if(a)
        q.push({a,'a'});
        if(b)
        q.push({b,'b'});
        if(c)
        q.push({c,'c'});
        while(q.size()){
            auto [freq,ch]=q.top();
            q.pop();
            if(ans.size()>=2 && ans[ans.size()-2]==ch && ans[ans.size()-1]==ch){
                if(q.empty()){
                    return ans;
                }
            auto [freq1,ch1]=q.top();
                q.pop();
                ans=ans+ch1;
                freq1--;
                if(freq1){
                    q.push({freq1,ch1});
                }
                q.push({freq,ch});
            }
            else{
                cout<<"pls";
            ans=ans+ch;
            freq--;
            if(freq){
                q.push({freq,ch});
            }
            }
        }
        return ans;
    }
};