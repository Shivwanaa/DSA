class Solution {
public:
    int compress(vector<char>& chars) {
        int count=0;
        string temp;
        int j=1;
        char c=chars[0];
        for(int i=0;i<chars.size();i++){
            if(c==chars[i]){
                count++;
            }
            else{
                if(count > 1) {
                    temp=to_string(count);
                    for(auto k:temp){
                        chars[j++]=k;
                    }
                }
                count=1;
                c=chars[i];
                chars[j++] = chars[i];
            }
        }
        if(count > 1) {
            temp=to_string(count);
            for(auto k:temp){
                chars[j++]=k;
            }
        }
        return j;
    }
};