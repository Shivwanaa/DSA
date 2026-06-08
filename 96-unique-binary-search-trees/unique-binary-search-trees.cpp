class Solution {
public:
unordered_map<int,int>m;
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        if(m.count(n)){
            return m[n];
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res=res+numTrees(i-1)*numTrees(n-i);
        }
        m[n]=res;
        return m[n];
    }
};