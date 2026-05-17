class Solution {
public:
    string alienOrder(vector<string>& words) {
        //try making a map
        string ans="";
        unordered_map<char,vector<char>>m;
        unordered_map<char,int>in;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                
                in[words[i][j]]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            int ms=min(words[i].size(),words[i+1].size());
            bool f=false;
            for(int j=0;j<ms;j++){
                if(words[i][j]!=words[i+1][j]){
                    m[words[i][j]].push_back(words[i+1][j]);
                    cout<<words[i+1][j]<<" ";
                    in[words[i+1][j]]++;
                    f=true;
                    break;
                }
                
            }
            if(!f && words[i].size()>words[i+1].size()){
                return "";
            }
        }
        queue<char>q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        while(q.size()){
            char cf=q.front();
            q.pop();
            ans+=cf;
            for(auto i:m[cf]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=in.size()){
            return "";
        }
        return ans;
    }
};