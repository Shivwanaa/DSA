class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        int midx=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            midx=max(m[s[j]],midx);
            if(midx==j){
                ans.push_back(j-i+1);
                i=j+1;
            }
        }
        return ans;
    }
};