class Solution {
public:
    bool check(int i,int a,int b,int c,int d,int s,vector<int>& matchsticks){
        if(i==matchsticks.size() && a==s && b==s && c==s && d==s){
            return true;
        }
        if(i==matchsticks.size()){
            return false;
        }
        bool ans=false;
        if(a+matchsticks[i]<=s){
        ans=ans||check(i+1,a+matchsticks[i],b,c,d,s,matchsticks);
        if(ans){
            return true;
        }
        }
        if(b+matchsticks[i]<=s){
        ans=ans||check(i+1,a,b+matchsticks[i],c,d,s,matchsticks);
        if(ans){
            return true;
        }
        }
        if(c+matchsticks[i]<=s){
        ans=ans||check(i+1,a,b,c+matchsticks[i],d,s,matchsticks);
        if(ans){
            return true;
        }
        }
        if(d+matchsticks[i]<=s){
        ans=ans||check(i+1,a,b,c,d+matchsticks[i],s,matchsticks);
        if(ans){
            return true;
        }
        }

        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int s=0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        for(int i=0;i<matchsticks.size();i++){
            s=s+matchsticks[i];
        }
        if(s%4!=0){
            return false;
        }
        return check(0,0,0,0,0,s/4,matchsticks);
    }
};