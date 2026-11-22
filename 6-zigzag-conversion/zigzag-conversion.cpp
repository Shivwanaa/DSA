class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length())
            return s;
        vector<string>an(numRows);
        int r=0,d=1;
        for(int i=0;i<s.size();i++){
            an[r].push_back(s[i]);
            if(r==numRows-1){
                d=-1;
            }
            else if(r==0){
                d=1;
            }
            r=r+d;
        }
        string ans;
        for(auto i:an){
            ans=ans+i;
        }
        return ans;
    }

};