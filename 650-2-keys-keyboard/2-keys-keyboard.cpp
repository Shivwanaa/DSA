class Solution {
public:
vector<int>m;
    int check(int n,int cl,int copied,int cancopy){
        if(cl==n){
            return 0;
        }
        if(cl>n){
            return 1e9;
        }
        int paste=1e9;
        int copy=1e9;
        if(cancopy)
        copy=1+check(n,cl,cl,0);
        if(copied)
        paste=1+check(n,cl+copied,copied,1);
        return min(copy,paste);
    }
    int minSteps(int n) {
        //2 options-sopy/paste
        vector<int>m(n+1);
        int ans=check(n,1,0,1);
        return ans;
    }
};