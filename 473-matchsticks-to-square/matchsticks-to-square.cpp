class Solution {
public:

    bool check(int i,vector<int>& matchsticks,int a,int b,int c,int d){
        if(a==0 && b==0 && c==0 && d==0){
            return true;
        }
        if(i>=matchsticks.size()||a<0||b<0||c<0||d<0){
            return false;
        }
        if(matchsticks[i]<=a && check(i+1,matchsticks,a-matchsticks[i],b,c,d)){
            return true;
        }
        if(matchsticks[i]<=b && b!=a && check(i+1,matchsticks,a,b-matchsticks[i],c,d)){
            return true;
        }
        if(matchsticks[i]<=c && c!=a && c!=b && check(i+1,matchsticks,a,b,c-matchsticks[i],d)){
            return true;
        }
        if(matchsticks[i]<=d && d!=a && d!=b&& d!=c && check(i+1,matchsticks,a,b,c,d-matchsticks[i])){
            return true;
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++){
            sum=sum+matchsticks[i];
        }
        if(sum%4!=0){
            return false;
        }
        sort(matchsticks.rbegin(),matchsticks.rend());
        int side=sum/4;
        return check(0,matchsticks,side,side,side,side);
    }
};