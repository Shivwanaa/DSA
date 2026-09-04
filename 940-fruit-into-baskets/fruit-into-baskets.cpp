class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,ans=0;
        unordered_map<int,int>m;
        for(int j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            while(i<j && m.size()>2){
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