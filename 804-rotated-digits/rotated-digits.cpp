class Solution {
public:
    int check(int n){
        bool valid=false;
        while(n){
            int a=n%10;
            if(a==3||a==4||a==7){
                return false;
            }
            if(a==2||a==5||a==6||a==9){
                valid=true;
            }
            n=n/10;
        }
        return valid;;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(check(i)){
                ans++;
            }
        }
        return ans;
    }
};