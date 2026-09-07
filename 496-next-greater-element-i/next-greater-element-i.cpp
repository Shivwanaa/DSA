class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        stack<int>s;
        unordered_map<int,int>m;
        for(int j=nums2.size()-1;j>=0;j--){
            while(!s.empty() && s.top()<=nums2[j]){
                s.pop();
            }
            if(!s.empty()){
                m[nums2[j]]=s.top();
            }
            else{
                m[nums2[j]]=-1;
            }
            s.push(nums2[j]);
        }
        for(int i=0;i<nums1.size();i++){
            ans[i]=m[nums1[i]];
        }
        return ans;
    }
};