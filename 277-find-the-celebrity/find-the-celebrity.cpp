/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>in(n,0);
        vector<int>out(n,0);
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && knows(i,j)){
                    in[j]++;
                    out[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<in[i]<<" "<<out[i]<<endl;
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
        return -1;
    }
};