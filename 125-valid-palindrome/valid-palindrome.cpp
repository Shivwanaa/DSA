class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        if(s.size()==1){
            return true;
        }

        while(i<=j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};