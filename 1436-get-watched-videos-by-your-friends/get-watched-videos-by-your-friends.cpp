class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<pair<int,int>>q;
        vector<string>ans;
        vector<int>temp;
        q.push({id,0});
        unordered_set<int>fr;
        unordered_map<string,int>a;
        while(q.size()){
            auto[f,l]=q.front();
            q.pop();
            fr.insert(f);
            if(l>level){
                break;
            }
            if(l==level){
                for(auto j:watchedVideos[f]){
                    a[j]++;
                }
                temp.push_back(f);
            }
            for(auto i:friends[f]){
                if(!fr.count(i)){
                    fr.insert(i);
                q.push({i,l+1});
                }
            }
        }
        for(auto i:a){
            ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end(),[&](string &b,string &c){
            if(a[b]==a[c]){
                return b<c;
            }
            return a[b]<a[c];
        });
        return ans;
        return ans;
    }
};