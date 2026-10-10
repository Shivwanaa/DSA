class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int>v;
        unordered_map<int,int>m;
        int i=0;
        int ans=0;
        for(int j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0){
                    m.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};