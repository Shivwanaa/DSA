class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>m;
        for(auto i:hand){
            m[i]++;
        }
        sort(hand.begin(),hand.end());
        int gs=1;
        for(int i=0;i<hand.size();i++){
            if(m[hand[i]]==0){
                continue;
            }
            else{
            int curr=hand[i];
             m[curr]--;
             if(m[hand[i]]==0){
                m.erase(hand[i]);
            }
            while(gs<groupSize){
                if(m.find(curr+1)!=m.end()){
                    m[curr+1]--;
                    if(m[curr+1]==0){
                        m.erase(curr+1);
                    }
                    curr=curr+1;
                }
                else{
                    return false;
                }
                gs++;
            }
            }
            gs=1;
        }
        return true;
    }
};