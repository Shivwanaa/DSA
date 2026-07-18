class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m;
        for(auto i:s1){
            m[i]++;
        }
        unordered_map<char,int>mm;
        unordered_map<char,int>match;
        int i=0;
        for(int j=0;j<s2.size();j++){
            match[s2[j]]++;
            if(j-i+1==s1.size()){
                if(m==match)
                return true;
                match[s2[i]]--;
                if(match[s2[i]]==0){
                    match.erase(s2[i]);
                }
                i++;
            }

        }
        return false;
    }
};