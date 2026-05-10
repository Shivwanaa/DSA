class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        vector<int>ans;
        string valid="";
        unordered_map<string,int>m;
        for(int i=0;i<chunks.size();i++){
            valid+=chunks[i];
        }
        string t="";
        for(int i=0;i<valid.size();i++){
            if(islower(valid[i])){
                t+=valid[i];
            }
            else if(valid[i]=='-' && i>0 && islower(valid[i-1]) && i<valid.size()-1 && islower(valid[i+1])){
                t+=valid[i];
            }
            else{
                if(!t.empty()){
                    m[t]++;
                }
                t="";
            }
        }
        if (!t.empty()) {
            m[t]++;
        }
        for(auto q:queries){
            ans.push_back(m[q]);
        }
        return ans;
    }
};
