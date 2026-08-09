class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<int>>m;
        wordList.push_back(beginWord);
        int l=0;
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].size();j++){
                string t=wordList[i];
                if(t==endWord){
                    l=1;
                }
                t[j]='*';
                m[t].insert(i);

            }
        }
        if(l==0){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        unordered_set<string>v;
        v.insert(beginWord);
        while(q.size()){
            auto[word,steps]=q.front();
            q.pop();
            if(word==endWord){
                return steps+1;
            }
            for(int i=0;i<word.size();i++){
                string t=word;
                t[i]='*';
                for(auto i:m[t]){
                    if(!v.count(wordList[i])){
                        v.insert(wordList[i]);
                    q.push({wordList[i],steps+1});
                    }
                }
            }
        }
        return 0;
    }
};