class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans="";
        for(auto i:s){
            if(i=='*'){
                st.pop();
            }
            else{
            st.push(i);
            }
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};