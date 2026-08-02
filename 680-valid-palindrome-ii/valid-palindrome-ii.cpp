class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        bool ans=true;
        int c=0;
        while(l<r){
            if(c==1 && s[l]!=s[r]){
                ans=false;
            }
            if(s[l]!=s[r]){
                l++;
                c=1;
            }
            else{
                l++;
                r--;
            }
        }
        l=0;
        r=s.size()-1;
        bool ans1=true;
        c=0;
        while(l<r){
            if(c==1 && s[l]!=s[r]){
                ans1=false;
            }
            if(s[l]!=s[r]){
                r--;
                c=1;
            }
            else{
                l++;
                r--;
            }
        }
        return ans||ans1;
    }
};