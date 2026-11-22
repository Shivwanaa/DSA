class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if((st.size() && st.top().first!=s[i])||st.empty())
            st.push({s[i],1});
            else if(st.size() && st.top().first==s[i]){
                st.top().second++;
            }
            if(st.size() && st.top().second==k){
                st.pop();
            }
        }
        string ans;
        while(st.size()){
            int freq=st.top().second;
            while(freq){
                ans.push_back(st.top().first);
                freq--;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};