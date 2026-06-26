class Solution {
public:
int dp[101][101][101];
    int check(vector<int>& boxes,int i,int j,int count){
        if(j-i<0){
            return 0;
        }
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }
        int ii=i;
        int jj=j;
        int count1=count;
        while(i+1<j && boxes[i]==boxes[i+1]){
            i++;
            count++;
        }
        int best=(count+1)*(count+1)+check(boxes,i+1,j,0);
        for(int k=i+1;k<=j;k++){
            if(boxes[k]==boxes[i]){
                best=max(best,check(boxes,i+1,k-1,0)+check(boxes,k,j,count+1));
            }
        }
        return dp[ii][j][count1]=best;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp)); 
        return check(boxes,0,boxes.size()-1,0);
    }
};