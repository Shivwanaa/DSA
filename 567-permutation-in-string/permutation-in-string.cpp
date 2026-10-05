class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(auto i:s1){
            m1[i]++;
        }
        int i=0;
        for(int j=0;j<s2.size();j++){
            m2[s2[j]]++;
            if(j-i+1==s1.size()){
                if(m1==m2)
                return true;

                m2[s2[i]]--;
                if(m2[s2[i]]==0){
                    m2.erase(s2[i]);
                }
                i++;
            }
        }
        return false;
    }
};