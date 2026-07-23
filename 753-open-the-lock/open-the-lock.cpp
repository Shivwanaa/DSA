class Solution {
public:
    vector<string>childs(string t){
        vector<string>res;
        for(int i=0;i<4;i++){
            string nxt=t;
            nxt[i]=((nxt[i]-'0'+1)%10+'0');
            res.push_back(nxt);
            nxt=t;
            nxt[i]=((nxt[i]-'0'-1+10)%10+'0');
            res.push_back(nxt);
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead;
        for(auto i:deadends){
            dead.insert(i);
        }
        if(dead.count("0000")){
            return -1;
        }
        string start="0000";
        queue<pair<string,int>>q;
        q.push({start,0});
        dead.insert(start);
        while(q.size()){
            auto[t,steps]=q.front();
            q.pop();
            if(t==target){
                return steps;
            }
            for(auto i:childs(t)){
                if(!dead.count(i)){
                    dead.insert(i);
                    q.push({i,steps+1});
                }
            }
        }
        return -1;
    }
};