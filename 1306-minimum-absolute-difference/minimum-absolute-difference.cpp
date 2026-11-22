class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int minDiff=1e9;
        for(int i=1;i<arr.size();i++){
            minDiff=min(minDiff,abs(arr[i-1]-arr[i]));
            // minDiff=min(minDiff,abs(arr[i]-arr[i+1]));
        }
        for(int i=1;i<arr.size();i++){
            if(minDiff==abs(arr[i-1]-arr[i])){
                ans.push_back({arr[i-1],arr[i]});
            }
            // if(minDiff==abs(arr[i]-arr[i+1])){
            //     ans.push_back({arr[i],arr[i+1]});
            // }
        }
        return ans;
    }
};