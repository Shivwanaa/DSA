class Solution {
public:
    string decodeString(string s) {
        stack<int>snum;
        stack<string>st;
        int n=0;
        string temp="";
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push(temp);
                snum.push(n);
                n=0;
                temp="";
            }
            else if(s[i]==']'){
                string temp1="";
                for(int i=0;i<snum.top();i++){
                    temp1=temp1+temp;
                }
                temp=st.top()+temp1;
                st.pop();
                snum.pop();
            }
            else if(isalpha(s[i])){
                temp=temp+s[i];
            }
            else{
                n=n*10+(s[i]-'0');
            }
        }
        
        return temp;
    }
};