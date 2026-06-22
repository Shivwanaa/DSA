class Solution {
public:
vector<vector<int>>dp;
    int check(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==nums1.size() ||j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(nums1[i]==nums2[j]){
            return dp[i][j]= 1+check(nums1,nums2,i+1,j+1);
        }
        return dp[i][j]=max(check(nums1,nums2,i,j+1),check(nums1,nums2,i+1,j));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp=vector<vector<int>>(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return check(nums1,nums2,0,0);
    }
};