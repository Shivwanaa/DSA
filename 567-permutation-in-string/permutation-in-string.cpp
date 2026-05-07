class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
        unordered_map<char,int>m;
        unordered_map<char,int>mtemp;
        for(auto i:s1){
            m[i]++;
        }
        int i=0;
        for(int j=0;j<s2.size();j++){
            mtemp[s2[j]]++;
            if(mtemp==m){
                return true;
            }
            if(j-i+1==s1.size()){
                mtemp[s2[i]]--;
                if(mtemp[s2[i]]==0){
                    mtemp.erase(s2[i]);
                }
                i++;
            }

        }
        return false;
    }
};