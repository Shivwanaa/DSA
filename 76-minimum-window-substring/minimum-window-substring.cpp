class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mor;
        unordered_map<char,int>m;
        for(auto i:t){
            mor[i]++;
        }
        int closed=mor.size();
        int j=0;
        int idx=-1;
        int c=0;
        int len=1e9;
        for(int i=0;i<s.size();i++){
            
            if(mor.find(s[i])!=m.end()){
            m[s[i]]++;
            if(m[s[i]]==mor[s[i]]){
                c++;
            }
            }
            while(c==closed){
                if(len>i-j+1){
                    len=i-j+1;
                    idx=j;
                }
                if(m.find(s[j])!=m.end()){
                    m[s[j]]--;
                    if(m[s[j]]<mor[s[j]]){
                        c--;
                    }
                }
                j++;
            }

        }
        if(idx==-1){
            return "";
        }
        return s.substr(idx,len);
    }
};