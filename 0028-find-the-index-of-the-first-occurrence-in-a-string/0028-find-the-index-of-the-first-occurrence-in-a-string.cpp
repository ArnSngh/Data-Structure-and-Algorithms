class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);  // Find The first Occurance of the Needle String , If found return the Index of 1st Aplhabet or if not retuen -1;
    }
};