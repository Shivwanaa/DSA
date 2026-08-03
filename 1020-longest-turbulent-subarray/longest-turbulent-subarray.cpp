class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1){
            return 1;
        }
        vector<int>temp(arr.size(),0);
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]){
                temp[i]=1;
            }
            else if(arr[i-1]==arr[i]){
                temp[i]=0;
            }
            else{
                temp[i]=-1;
            }
        }
        int j=0;
        int ans=0;
        for(int i=1;i<temp.size();i++){
            if(temp[i]==0){
                j=i;
            }
            else if(temp[i-1]!=0 && temp[i-1]==temp[i]){
                j=i-1;
            }
            ans=max(ans,i-j+1);
        }

        return ans;
    }
};