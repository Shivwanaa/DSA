class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg=0,sc=0;
        for(int i=0;i<gas.size();i++){
            sg=sg+gas[i];
            sc=sc+cost[i];
        }
        if(sg<sc){
            return -1;
        }
        int tot=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            tot=tot+gas[i]-cost[i];
            if(tot<0){
                tot=0;
                ans=i+1;
            }
        }
        return ans;
    }
};