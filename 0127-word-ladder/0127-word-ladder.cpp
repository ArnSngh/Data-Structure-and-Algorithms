class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> wordset;

        for(auto i : wordList){
            wordset[i]++;
        }

        if(wordset.find(endWord) == wordset.end()){
            return 0;
        }

        queue<pair<string,int>> qt;
        qt.push({beginWord,1});

        while(!qt.empty()){
            auto [word,step] = qt.front();
            qt.pop();

            for(int i = 0; i < word.size(); i++){
                string temp = word;

                for(char c = 'a'; c <= 'z'; ++c){
                    temp[i] = c;

                    if(temp == endWord){
                        return step + 1;
                    }

                    if(wordset.find(temp) != wordset.end()){
                        qt.push({temp,step + 1});
                        wordset.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};