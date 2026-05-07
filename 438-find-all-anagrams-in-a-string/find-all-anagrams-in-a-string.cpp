class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>m;
        unordered_map<char,int>mtemp;
        for(auto i:p){
            m[i]++;
        }
        int i=0;
        for(int j=0;j<s.size();j++){
            mtemp[s[j]]++;
            if(mtemp==m){
                ans.push_back(i);
            }
            if(j-i+1==p.size()){
                mtemp[s[i]]--;
                if(mtemp[s[i]]==0){
                    mtemp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};