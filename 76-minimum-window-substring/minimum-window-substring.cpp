class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>origin;
        for(auto i:t){
            origin[i]++;
        }
        int count=origin.size();
        unordered_map<char,int>temp;
        int i=0;
        int curr=0;
        int mi=-1,mj=-1;
        for(int j=0;j<s.size();j++){
            if(origin.find(s[j])!=origin.end()){
                temp[s[j]]++;
                if(temp[s[j]]==origin[s[j]]){
                curr++;
            }
            }
            while(curr==count){
                if(mi==-1 || j-i < mj-mi){
                    mi=i;
                    mj=j;
                }
                if(temp.find(s[i])!=temp.end()){
                    temp[s[i]]--;
                    if(temp[s[i]]<origin[s[i]])
                    curr--;
                }
                i++;
            }
        }
        if(mi==-1 || mj==-1){
            return "";
        }
        // cout<<mi<< " "<<mj;
        return s.substr(mi,mj-mi+1);
    }
};