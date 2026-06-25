class Solution {
public:
int dp[101][101][101];
    int check(vector<int>& boxes,int i,int j,int count){
        if(j-i<0){
            return 0;
        }
        int counthere=count;
        int ihere=i;
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }
        while(i+1<j && boxes[i]==boxes[i+1]){
            i++;
            count++;
        }
        int ans=(count+1)*(count+1)+check(boxes,i+1,j,0);
        for(int idx=i+1;idx<=j;idx++){
            if(boxes[i]==boxes[idx]){
                ans=max(ans,check(boxes,i+1,idx-1,0)+check(boxes,idx,j,count+1));
            }
        }
        return dp[ihere][j][counthere]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp)); 
        return check(boxes,0,boxes.size()-1,0);
    }
};

