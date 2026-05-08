class Solution {
public:
vector<string>ans;
    void check(int n,int i,string tp,int u,int l){
        if(i>n*2){
            return;
        }
        if(i==n*2){
            ans.push_back(tp);
            return;
        }
        if(u<n)
        check(n,i+1,tp+'(',u+1,l);
        if(u>l)
        check(n,i+1,tp+')',u,l+1);
    }
    vector<string> generateParenthesis(int n) {
        string tp;
        check(n,0,tp,0,0);
        return ans;
    }
};