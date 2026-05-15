class Solution {
public:
unordered_set<string>s;
    void check(string tiles,int i,string tp,vector<int>freq){
        s.insert(tp);
        for(int j=0;j<tiles.size();j++){
            if(!freq[j]){
                freq[j]=1;
                tp.push_back(tiles[j]);
                check(tiles,j,tp,freq);
                freq[j]=0;
                tp.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int ans=0;
        //permutation+subsets
        vector<int>freq(tiles.size(),0);
        check(tiles,0,"",freq);
        return s.size()-1;
    }
};