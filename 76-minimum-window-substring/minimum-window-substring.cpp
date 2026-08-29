class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(auto i:t){
            m[i]++;
        }
        int count=m.size();
        int c=0;
        unordered_map<char,int>mp;
        int l=-1,r=0;
        int len=1e9;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(m.find(s[j])!=m.end()){
                mp[s[j]]++;
                if(mp[s[j]]==m[s[j]]){
                    c++;
                }
            }
            while(c==count){
                if(j-i+1<len){
                l=i;
                r=j;
                len=r-l+1;
                }
                if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]]<m[s[i]]){
                    c--;
                }
                }
                i++;
            }
        }
        if(l==-1){
            return "";
        }
        return s.substr(l,r-l+1);
    }

};