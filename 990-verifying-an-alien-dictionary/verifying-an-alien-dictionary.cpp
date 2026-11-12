class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>ord;
        int c=0;
        for(auto i:order){
            
            ord[i]=c;
            c++;
        }
        for(int i=1;i<words.size();i++){
            for(int j=0;j<min(words[i-1].size(),words[i].size());j++){
                if(words[i][j]!=words[i-1][j]){
                    if(ord[words[i][j]]<ord[words[i-1][j]]){
                        return false;
                    }
                    break;
                }
                if(words[i].size()<words[i-1].size() && j==words[i].size()-1){
                    return false;
                }
            }

        }
        return true;
    }
};