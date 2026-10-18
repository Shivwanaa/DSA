class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        bool l=true;
        for(int i=0;i<asteroids.size();i++){
            l=true;
            while(st.size() && st.top()>0 && asteroids[i]<0){
                l=false;
                if(abs(st.top())==abs(asteroids[i])){
                    st.pop();
                    break;
                }
                else if(abs(st.top())>abs(asteroids[i])){
                    break;
                }
                else if(abs(st.top())<abs(asteroids[i])){
                    l=true;
                    st.pop();

                }
            }
            if(l)
            st.push(asteroids[i]);
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};