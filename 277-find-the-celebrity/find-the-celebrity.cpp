/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int check(int celeb,int n){

        for(int j=0;j<n;j++){
            if(j==celeb){
                continue;
            }
            if(!knows(j,celeb) || knows(celeb,j)){
                return -1;
            }
        }
        return celeb;
    }
    int findCelebrity(int n) {
        int celeb=0;
        for(int i=0;i<n;i++){
            if(knows(celeb,i)){
                celeb=i;
            }
        }
        return check(celeb,n);
    }
};