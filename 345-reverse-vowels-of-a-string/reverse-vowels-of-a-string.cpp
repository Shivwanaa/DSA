class Solution {
public:
    bool isvowel(char a){
        string v="AEIOUaeiou";
        for(auto i:v){
            if(a==i){
                return true;
            }
        }
        return false;
    }
    string reverseVowels(string s) {
        int l=0;
        int h=s.size()-1;
        while(l<h){
            if(isvowel(s[l]) && !isvowel(s[h])){
                h--;
            }
            else if(isvowel(s[h]) && !isvowel(s[l])){
                l++;
            }
            else{
                if(isvowel(s[l]) && isvowel(s[h])){
                    swap(s[l],s[h]);
                }
                l++;
                h--;
            }
        }
        return s;
    }
};