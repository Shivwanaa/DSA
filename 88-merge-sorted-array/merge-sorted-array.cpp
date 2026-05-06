class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ni;
        int i=0;
        int j=0;
        while(i<m || j<nums2.size()){
            if(i<m && j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    ni.push_back(nums1[i]);
                    i++;
                }
                else{
                    ni.push_back(nums2[j]);
                    j++;
                }
            }
            else if(i<m){
                ni.push_back(nums1[i]);
                i++;
            }
            else{
                ni.push_back(nums2[j]);
                j++;
            }
        }
        nums1=ni;
    }
};