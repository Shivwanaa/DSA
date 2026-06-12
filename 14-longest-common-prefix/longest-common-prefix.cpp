class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool endWord;
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode*node=root;
        for(auto i:word){
            if(node->children.find(i)==node->children.end()){
                node->children[i]=new TrieNode();
            }
            node=node->children[i];
        }
        node->endWord=true;

    }
    int comm(string word){
        TrieNode*node=root;
        for(int i=0;i<word.size();i++){
            if(node->children.find(word[i])==node->children.end()){
                return i;
            }
            node=node->children[word[i]];
        }
        return word.size();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minl=1e9;
        int idx=0;
        for(int i=0;i<strs.size();i++){
            if(minl>strs[i].size()){
                minl=strs[i].size();
                idx=i;
            }
        }
        Trie trie;
        int l=1e9;
        trie.insert(strs[idx]);
        for(auto i:strs){
             l=min(l,trie.comm(i.substr(0,minl)));
        }
        return strs[idx].substr(0,l);
    }
};