/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i=0;
        int j=mountainArr.length()-1;
        int idx=0;
        if(target<mountainArr.get(0) && target<mountainArr.get(j)){
            return -1;
        }
        while(i<=j){
            int mid=(i+j)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        cout<<idx;
        idx=i;
        if(mountainArr.get(idx)==target){
            return idx;
        }

        int l1=0;
        int r1=idx;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid)>target){
                r1=mid-1;
            }
            else{
                l1=mid+1;
            }
        }
        int l2=idx;
        int r2=mountainArr.length()-1;
        while(l2<=r2){
            int mid=(l2+r2)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid)>target){
                l2=mid+1;
                
            }
            else{
                r2=mid-1;
            }
        }
        return -1;
    }
};