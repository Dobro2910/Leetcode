class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> patternWordMap;
        vector<string> arrayOfWords;

        string word;
        stringstream ss(s);
        while (getline(ss, word, ' ')) {
            arrayOfWords.push_back(word);
        }

        if (arrayOfWords.size() != pattern.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            if (patternWordMap.count(pattern[i]) == 0) {
                for (auto &p : patternWordMap) {
                    if (p.second == arrayOfWords[i]) {
                        return false;
                    }
                }

                patternWordMap.insert({pattern[i], arrayOfWords[i]});
            } else if (patternWordMap[pattern[i]] == arrayOfWords[i]) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};