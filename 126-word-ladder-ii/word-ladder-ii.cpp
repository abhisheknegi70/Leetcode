class Solution {
public:
    unordered_map<string, vector<string>> parents;
    unordered_map<string, int> level;
    vector<vector<string>> ans;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < temp.size(); i++) {

                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    temp[i] = c;

                    if (!dict.count(temp))
                        continue;

                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    }
                    else if (level[temp] == currLevel + 1) {
                        parents[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};