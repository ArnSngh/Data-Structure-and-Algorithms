class Solution {
public:
    #define MAX 26

    // Function that return true if frequency
    // of all the present characters is at least k
    bool atLeastK(int freq[], int k)
    {
        for (int i = 0; i < MAX; i++) {
    
            // If the character is present and
            // its frequency is less than k
            if (freq[i] != 0 && freq[i] < k)
                return false;
        }
    
        return true;
    }

    void setZero(int freq[])
    {
        for (int i = 0; i < MAX; i++)
            freq[i] = 0;
    }


    int longestSubstring(string s, int k) {
        int n=s.length();
        int maxLen = 0;
 
        int freq[MAX];
    
        // Starting index of the sub-string
        for (int i = 0; i < n; i++) {
            setZero(freq);
    
            // Ending index of the sub-string
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
    
                // If the frequency of every character
                // of the current sub-string is at least k
                if (atLeastK(freq, k)) {
    
                    // Update the maximum possible length
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
    
        return maxLen;
    }
};