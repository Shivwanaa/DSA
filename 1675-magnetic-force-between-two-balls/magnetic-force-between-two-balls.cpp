class Solution {
public:
    bool check(vector<int>& position,int gap, int m){
        int balls=1;
        int lp=0;
        for(int i=1;i<position.size();i++){
            if(position[i]-position[lp]>=gap){
                balls++;
                lp=i;
            }
        }
        if(balls>=m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1;
        int r=position[position.size()-1]-position[0];
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(position,mid,m)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};