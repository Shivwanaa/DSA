class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<int>>m;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            m[word].push_back(i);
        }
        for(auto i:m){
            vector<string> t;
            for(auto j:m[i.first]){
                t.push_back(strs[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};