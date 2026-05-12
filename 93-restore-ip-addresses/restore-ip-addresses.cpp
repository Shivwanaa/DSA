class Solution {
public:
vector<string>ans;
    string toip(vector<string>t){
        string res="";
        for(auto i:t){
            res+=i;
            res+='.';
        }
        res.pop_back();
        return res;
    }
    void check(string s,int i,vector<string> t){
        if(t.size()==4 && i==s.size()){
            string d=toip(t);
            ans.push_back(d);
            return;
        }
        if(i>=s.size()){
            return;
        }
        for(int j=1;j<=3;j++){
            if(stoi(s.substr(i,j))<=255 ){
            if(j==1||j>1 && s[i]!='0'){
            t.push_back(s.substr(i,j));
            check(s,i+j,t);
            t.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        //4*3-max
        //start from end
        //1,2,3 possible -if results in 4 subparts-yes
        vector<string> t;
        check(s,0,t);
        return ans;
    }
};