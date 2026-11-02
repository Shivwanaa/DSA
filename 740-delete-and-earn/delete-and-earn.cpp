class Solution {
public:
vector<int>dp;
    int check(int i,vector<int>&temp,unordered_map<int,int>&m){
        if(i>=temp.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int earn=temp[i]*m[temp[i]];
        int p=0,np=0;
        if(i+1<temp.size() && temp[i]+1==temp[i+1]){
            p=earn+check(i+2,temp,m);
        }
        else{
            p=earn+check(i+1,temp,m);
        }
        np=check(i+1,temp,m);
        return dp[i]=max(p,np);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        vector<int>temp;
        for(auto i:m){
            temp.push_back(i.first);
        }
        dp=vector<int>(temp.size()+1,-1);
        sort(temp.begin(),temp.end());
        return check(0,temp,m);
    }
};