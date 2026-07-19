class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans(digits.size(),0);
        int c=0;
        int s=digits[digits.size()-1]+1;
        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1){
                s=digits[i]+1;
            }
            else{
                s=digits[i]+c;
            }
            if(s>9){
                c=1;
            }
            else{
                c=0;
            }
            ans[i]=s%10;
        }
        if(c){
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};