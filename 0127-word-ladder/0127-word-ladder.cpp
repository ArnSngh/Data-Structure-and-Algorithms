class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            string w = node.first;
            int cnt = node.second;

            if (w == endWord)
                return cnt;

            for (int i = 0; i < w.size(); i++) {
                char ch = w[i];

                for (char t = 'a'; t <= 'z'; t++) {
                    w[i] = t;

                    if (st.find(w) != st.end()) {
                        st.erase(w);
                        q.push({w, cnt + 1});
                    }
                }

                w[i] = ch;
            }
        }

        return 0;
    }
};