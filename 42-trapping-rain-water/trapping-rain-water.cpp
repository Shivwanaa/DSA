class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l(height.size(),0);
        vector<int>r(height.size(),0);
        l[0]=height[0];
        for(int i=1;i<height.size();i++){
            l[i]=max(height[i],l[i-1]);
        }
        r[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            r[i]=max(r[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            cout<<min(l[i],r[i])<<endl;
            if(min(l[i],r[i])-height[i]>0)
            ans=ans+min(l[i],r[i])-height[i];
        }
        return ans;
    }
};