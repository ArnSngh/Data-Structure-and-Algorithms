class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mpp;
    string b;
    int N;
public:
    // Backtracking DFS to backtrack from endWord to beginWord using the step levels in mpp
    void dfs(string word, vector<string> seq)
    {
        // Base case: Reached the beginWord
        if(b == word)
        {
            reverse(seq.begin(), seq.end()); // Reverse to get path from beginWord -> endWord
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // Backtrack reverse to keep state clean
            return;
        }
        
        // Explore all possible single-character variations
        for(int j = 0; j < N;j++)
        {
            int size = mpp[word]; // Current level of the word
            char original = word[j];
            
            for(char ch = 'a'; ch <= 'z';ch++)
            {
                word[j] = ch;
                
                // Check if candidate word exists in our visited step map
                if(mpp.count(word) > 0)
                {
                    // Only backtrack to nodes that are exactly 1 step closer to beginWord
                    if(mpp[word] + 1 == size)
                    {
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back(); // Backtrack step
                    }
                }
            }
            word[j] = original; // Restore original character
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        N = beginWord.length();
        queue<pair<string, int>> q;
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        set.erase(beginWord);
        int steps = 1;
        q.push({beginWord, steps});
        int length = beginWord.length();

        // Step 1: BFS to find the shortest distance level from beginWord to all reachable words
        while(!q.empty())
        {
            int N = q.size();
            for(int i = 0; i < N;i++)
            {
                pair<string, int> check = q.front();
                mpp[check.first] = check.second; // Store distance level
                q.pop();
                
                if(check.first == endWord)
                    break;
                
                string word = check.first;
                
                for(int j = 0; j < length;j++)
                {
                    char original = word[j];
                    for(char ch = 'a'; ch <= 'z';ch++)
                    {
                        word[j] = ch;
                        if(set.count(word))
                        {
                            set.erase(word);
                            q.push({word, steps+1});
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }

        // Step 2: Backtrack from endWord to beginWord using DFS
        b = beginWord;
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
        
        return ans;
    }
};