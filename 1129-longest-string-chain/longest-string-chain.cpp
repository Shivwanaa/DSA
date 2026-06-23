class Solution {
public:
vector<vector<int>>dp;
    bool subs(string prev, string word) {
        if (word.size() != prev.size() + 1) {
            return false;
        }
        int i = 0, j = 0;
        bool skipped = false;
        while (i < prev.size() && j < word.size()) {
            if (prev[i] == word[j]) {
                i++;
                j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int check(vector<string>& words, int i, int prev) {
        if (i == words.size()) {
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int a = 0;
        if (prev==-1||subs(words[prev], words[i])) {
            a =1+check(words,i+1,i);
        }
        int b = check(words,i+1,prev);
        return dp[i][prev+1]=max(a,b);
    }

    int longestStrChain(vector<string>& words) {
        dp=vector<vector<int>>(words.size()+1,vector<int>(words.size()+1,-1));
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) {
                 return a.size() < b.size();
             });
        return check(words, 0, -1);
    }
};