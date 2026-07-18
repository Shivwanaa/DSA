class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>s;
        for(int i=0;i<asteroids.size();i++){
            int temp=asteroids[i];
            if(temp>0||s.empty()){
                s.push(temp);
            }
            else{
                while(s.size() && s.top()>0 && s.top()<(-temp)){
                    s.pop();
                }
                if(s.empty()||s.top()<0){
                    s.push(temp);
                }
                if(s.size() && s.top()==-temp){
                    s.pop();
                }
            }
            
        }
        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};