class Solution {
public:
vector<string>ans;
    void check(int i,string digits,unordered_map<int,string>&m,string tp){
        if(tp.size()==digits.size()){
            ans.push_back(tp);
            return;
        }
        for(auto j:m[digits[i]-'0']){
            check(i+1,digits,m,tp+j);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        check(0,digits,m,"");
        return ans;
    }
};