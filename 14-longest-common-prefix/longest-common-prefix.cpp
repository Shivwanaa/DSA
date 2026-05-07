class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string l=strs[0];
        string h=strs[strs.size()-1];
        string ans;
        for(int i=0;i<(l.size(),h.size());i++){
            if(l[i]==h[i]){
                ans=ans+l[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};