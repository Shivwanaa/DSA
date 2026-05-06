class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        sort(strs.begin(),strs.end());
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(t);
        }
        vector<string>temp;
        for(auto i:m){
            temp={};
            for(auto j:i.second){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};