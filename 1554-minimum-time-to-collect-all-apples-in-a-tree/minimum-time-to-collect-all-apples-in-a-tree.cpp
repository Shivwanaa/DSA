class Solution {
public:
    bool check(unordered_map<int,vector<int>>&m,int node,int p,vector<bool>& hasApple,vector<int>&hasapple){
        hasapple[node]=hasApple[node];
        for(auto i:m[node]){
            if(i!=p){
            check(m,i,node,hasApple,hasapple);
            hasapple[node]=hasapple[node]||hasapple[i];
            }
        }
        return hasapple[node];
    }
    int check1(unordered_map<int,vector<int>>&m,vector<int>&hasapple,int node,int p,int t){
        int ans=0;
        for(auto i:m[node]){
            if(i!=p){
                if(hasapple[i]){
                    ans+=2+check1(m,hasapple,i,node,t);
                }
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>hasapple(n,0);
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        check(m,0,-1,hasApple,hasapple);
        return check1(m,hasapple,0,-1,0);
    }
};