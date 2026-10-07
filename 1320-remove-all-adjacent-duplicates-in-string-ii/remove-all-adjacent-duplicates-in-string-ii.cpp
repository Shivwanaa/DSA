class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;

        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top().first==s[i]){
                if(st.top().second+1==k){
                st.pop();
                }
                else{
                    st.top().second++;
                }
            }
            else
            st.push({s[i],1});
        }
        string ans="";
        while(st.size()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};