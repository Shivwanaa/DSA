class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>main;
        for(auto i:s){
            main[i]++;
        }
        unordered_map<char,int>m;
        int formed=0;
        int i=0;
        vector<int>ans;
        for(int j=0;j<s.size();j++){
            m[s[j]]++;
            if(m[s[j]]==main[s[j]]){
                formed++;
            }
            if(formed==m.size()){
                ans.push_back(j-i+1);
                i=j+1;
                formed=0;
                m.clear();
            }
        }
        return ans;
    }
};