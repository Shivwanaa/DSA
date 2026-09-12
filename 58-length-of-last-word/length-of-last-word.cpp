class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(ans==0 && s[i]==' '){
                continue;
            }
            else if(s[i]==' '){
                break;
            }
            else
            ans++;
        }
        return ans;
    }
};