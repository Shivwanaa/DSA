class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                if(triplets[i][0]==target[0]){
                    a++;
                }
                if(triplets[i][1]==target[1]){
                    b++;
                }
                if(triplets[i][2]==target[2]){
                    c++;
                }
            }
        }
        if(a>=1 && b>=1 && c>=1) return true;
        return false;

    }
};