class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool endWord;
};
class WordDictionary {
public:
TrieNode*root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode*node=root;
        for(auto i:word){
            if(node->children.find(i)==node->children.end()){
                node->children[i]=new TrieNode();
            }
            node=node->children[i];
        }
        node->endWord=true;
    }
    bool searchdot(string word,TrieNode*node){
        for(int i=0;i<word.size();i++){
            if(node->children.find(word[i])==node->children.end()){
                if(word[i]=='.'){
                    for(auto j:node->children){
                        TrieNode*t=j.second;
                        if(searchdot(word.substr(i+1),t)){
                            return true;
                        }
                    }
                }
                    return false;
            }
            else
            node=node->children[word[i]];
        }
        return node->endWord;
    }

    bool search(string word) {
        TrieNode*node=root;
        return searchdot(word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */