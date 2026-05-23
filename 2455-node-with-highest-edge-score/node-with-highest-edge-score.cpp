class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long long>m;
        for(int i=0;i<edges.size();i++){
            m[edges[i]]=m[edges[i]]+i;
        }
        long long a=0;
        for(auto i:m){
            if(i.second>a){
                cout<<i.first;
                a=i.second;
            }
        }
        int ans=1e9;
        for(auto i:m){
            if(i.second==a && ans>i.first){
                cout<<i.first;
                ans=i.first;
            }
        }
        // for(auto i:edges){
        //     if(temp.find(i)!=temp.end()){
        //         return i;
        //     }
        // }
        return ans;
    }
};