class Solution {
public:
vector<vector<string>>ans;
    bool pall(int si,int e,string s){
        while(si<=e){
            if(s[si]!=s[e]){
                return false;
            }
            si++;
            e--;
        }
        return true;
    }
    void parti(int i,string s,vector<string> t){
        if(i==s.size()){
            ans.push_back(t);
            return;
        }
        for(int j=i;j<s.size();j++){
           if(pall(i,j,s)){
            t.push_back(s.substr(i,j-i+1));
            parti(j+1,s,t);
            t.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>t;
        parti(0,s,t);
        return ans;
    }
};