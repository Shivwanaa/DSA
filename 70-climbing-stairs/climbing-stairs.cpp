class Solution {
public:
vector<int>m;
    int climb_Stairs(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(m[n]!=0){
            return m[n];
        }
        int a=climb_Stairs(n-1);
        int b=climb_Stairs(n-2);
        return m[n]=a+b;
    }
    int climbStairs(int n) {
        m=vector<int>(n+1,0);
        return climb_Stairs(n);
    }
};