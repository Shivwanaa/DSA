class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        unordered_map<char,char>mrev;
        for(int i=0;i<s.size();i++){
            if((m.find(s[i])!=m.end() && m[s[i]]!=t[i])||(mrev.find(t[i])!=mrev.end() && mrev[t[i]]!=s[i])){

                return false;
            }
            m[s[i]]=t[i];
            mrev[t[i]]=s[i];
        }
        return true;
    }
};