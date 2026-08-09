class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<tuple<int,int,int,int>>q;
        int totkeys=0;
        int s=0,e=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@'){
                    s=i,e=j;
                    // q.push({i,j,0});
                }
                if(grid[i][j]>='a' && grid[i][j]<='z'){
                    totkeys++;
                }
            }
        }
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int allKeys=(1<<totkeys)-1;
        set<tuple<int,int,int>>v;
        q.push({s,e,0,0});
        v.insert({s,e,0});
        while(q.size()){
            auto [r,c,keysMask,steps]=q.front();
            q.pop();
            if(keysMask==allKeys){
                return steps;
            }
            for(auto k:dir){
                int nMask=keysMask;
                int nr=r+k[0];
                int nc=c+k[1];
                if(nr<0||nc<0||nr>=grid.size()||nc>=grid[0].size()||grid[nr][nc]=='#'){
                    continue;
                }
                char temp=grid[nr][nc];
                if(temp>='A' && temp<='Z'){
                    int shift=(temp-'A');
                    if((nMask&(1<<shift))==0){
                        continue;
                    }
                }
                if(temp>='a' && temp<='z'){
                    int shift=temp-'a';
                    nMask|=(1<<shift);
                }
                if(v.count({nr,nc,nMask})){
                    continue;
                }
                v.insert({nr,nc,nMask});
                q.push({nr,nc,nMask,steps+1});
            }
        }
        return -1;
    }
};