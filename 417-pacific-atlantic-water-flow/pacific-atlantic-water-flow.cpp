class Solution {
public:
bool a=false,p=false;
    void check(int i,int j,vector<vector<int>>& heights,map<pair<int,int>,bool>&v,int par){
        //both p and atlantic;
        //(i==0 || j==0) && (i==heights.size()-1 || j==heights[0].size()-1)
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size()){
            return;
        }
        if(p && a){
            return;
        }
        if(par<heights[i][j]){
            return;
        }
        if(i==0 || j==0){
            p=true;
        }
        if(i==heights.size()-1 || j==heights[0].size()-1){
            a=true;
        }
        int t=heights[i][j];
        heights[i][j]=1e9;
        check(i+1,j,heights,v,t);
        check(i-1,j,heights,v,t);
        check(i,j+1,heights,v,t);
        check(i,j-1,heights,v,t);
        heights[i][j]=t;
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        // set<pair<int,int>>v;
        map<pair<int,int>,bool>v;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                a=false;
                p=false;
                check(i,j,heights,v,1e9);
                if(a && p){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
