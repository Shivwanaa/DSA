class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int is=0,js=matrix[0].size()-1;
        int ie=matrix.size()-1,je=0;
        cout<<is<<ie<<js<<je<<" ";
        while(is <= ie && je <= js){
        for(int j=je;j<=js;j++){
            ans.push_back(matrix[is][j]);
        }
        is++;
        for(int i=is;i<=ie;i++){
            ans.push_back(matrix[i][js]);
        }
        js--;
        if(is<=ie){
        for(int j=js;j>=je;j--){
            ans.push_back(matrix[ie][j]);
        }
        ie--;
        }
        if(js>=je){
        for(int i=ie;i>=is;i--){
            ans.push_back(matrix[i][je]);
        }
        je++;
        }
        }
        return ans;
    }
};