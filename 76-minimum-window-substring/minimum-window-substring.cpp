class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(auto i:t){
            m2[i]++;
        }
        int formed=m2.size();
        int needed=0;
        int i=0;
        int l=1e9;
        int mi=-1;
        for(int j=0;j<s.size();j++){
            if(m2.find(s[j])!=m2.end()){
                m1[s[j]]++;
                if(m1[s[j]]==m2[s[j]]){
                    needed++;
                }
            }
                while(formed==needed){
                    if(j-i+1<l){
                    l=j-i+1;
                    mi=i;
                }
                    if(m1.find(s[i])!=m2.end()){
                        m1[s[i]]--;
                        if(m1[s[i]]<m2[s[i]]){
                            needed--;
                        }
                    }
                    i++;
                }
        }
        if(mi==-1){
            return "";
        }
        return s.substr(mi,l);
    }
};