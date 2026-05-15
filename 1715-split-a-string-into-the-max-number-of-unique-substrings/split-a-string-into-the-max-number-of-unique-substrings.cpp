class Solution {
public:
int ans=0;
    void check(string s,unordered_set<string>m,int i,string t){
        if(i==s.size()){
            int l=m.size();
            ans=max(ans,l);
            return;
        }
        for(int j=1;j<=s.size();j++){
            if(i+j-1<s.size()){
            t=s.substr(i,j);
            if(m.count(t)==0){
                m.insert(t);
                check(s,m,i+j,t);
                m.erase(t);
            }
            }
            else{
                break;
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>m;
        //max no of max substrings
        check(s,m,0,"");
        return ans;
    }
};