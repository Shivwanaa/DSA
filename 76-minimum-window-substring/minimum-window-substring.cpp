class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        unordered_map<char,int>main;
        int i=0;
        int ml=1e9;
        int idx=-1;
        int formed=0;
        for(int j=0;j<s.size();j++){
            if(m.find(s[j])!=m.end()){
                main[s[j]]++;
                if(main[s[j]]==m[s[j]]){
                    formed++;
                }
            }
            while(formed==m.size() && i<s.size() && i<=j){
                if(ml>j-i+1){
                    idx=i;
                    ml=j-i+1;
                }
                if(main.find(s[i])!=main.end()){
                    main[s[i]]--;
                    if(main[s[i]]<m[s[i]]){
                        formed--;
                    }
                }
                i++;
            }
        }
        if(idx==-1){
            return "";
        }
        return s.substr(idx,ml);
    }
};