class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        // Frequency map for the target words
        // Since a word should exactly appear once (or as per its count) in the substring
        unordered_map<string, int> targetFreq;
        for (string& w : words) {
            targetFreq[w]++;
        }

        int n = s.size();
        int wordLen = words[0].length();
        int totalWords = words.size();

        // Setting the offset
        // Offset is required since we only want to iterate to the next valid index 
        // For example, if wordLen = 3 then iteration should be like i, i+3, i+6...
        /*
        Offset 0: 0, 3, 6, 9...
        Offset 1: 1, 4, 7, 10...
        Offset 2: 2, 5, 8, 11...
        */
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int cnt = 0;
            unordered_map<string, int> windowFreq;

            // Inner sliding window
            // We iterate by adding 'wordLen' to right each time
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                // Extract the word
                string word = s.substr(right, wordLen);

                // If the word exists inside the target 
                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    cnt++;

                    // Invariant -> windowFreq[word] <= targetFreq[word]
                    // If we have too many of this word, shrink from left
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        cnt--;
                    }

                    // If the count becomes equal to the totalWords
                    // We have hit a valid substring (exact number of words)
                    if (cnt == totalWords) {
                        ans.push_back(left);
                    }
                } 
                else { 
                    // If the word doesn't exist, it's an invalid sequence 
                    // Reset the cnt, clear the window, and set left to the next possible start
                    windowFreq.clear();
                    cnt = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};