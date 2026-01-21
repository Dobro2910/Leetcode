class Solution {
private:
    int bfs(int wordListSize, string beginWord, string endWord, unordered_map<string, int> wordIndexMapping, vector<vector<string>> adjacencyWordList) {
        vector<int> visitedWord(wordListSize + 1, 0);
        vector<int> backtracking(wordListSize + 1, 0);
        queue<int> wordToVisit;

        wordToVisit.push(wordIndexMapping[beginWord]);
        visitedWord[wordIndexMapping[beginWord]] = 1;

        bool foundEnd = false;
        int currentWordIndex = 0;
        while (!wordToVisit.empty()) {
            currentWordIndex = wordToVisit.front();
            wordToVisit.pop();

            for (const auto& neighbor : adjacencyWordList[currentWordIndex]) {
                int neighborIndex = wordIndexMapping[neighbor];

                if (visitedWord[neighborIndex] != 1) {
                    visitedWord[neighborIndex] = 1;
                    backtracking[neighborIndex] = currentWordIndex;

                    if (neighborIndex == wordIndexMapping[endWord]) {
                        currentWordIndex = wordIndexMapping[endWord];
                        foundEnd = true;
                        break;
                    } 

                    wordToVisit.push(neighborIndex);
                }
            }

            if (foundEnd == true) {
                break;
            } 
        }

        if (foundEnd == false) {
            return 0;
        }

        int result = 1;
        while(currentWordIndex != wordIndexMapping[beginWord]) {
            cout << "currentWordIndex: " << currentWordIndex << "\n";
            currentWordIndex = backtracking[currentWordIndex];
            ++result;
        }
        cout << "currentWordIndex: " << currentWordIndex << "\n";

        return result;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool foundEnd = false;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                foundEnd = true;
            }
        }

        if (foundEnd == false) {
            return 0;
        }

        int wordSize = beginWord.size();

        vector<vector<string>> adjacencyWordList(wordList.size() + 1);
        unordered_map<string, int> wordIndexMapping(wordList.size() + 1);

        int differentCount = 0;
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < wordSize; ++j) {
                if (beginWord[j] != wordList[i][j]) {
                    ++differentCount;
                }
            }

            if (differentCount == 1) {
                adjacencyWordList[0].push_back(wordList[i]);
            }

            wordIndexMapping[beginWord] = 0;
            differentCount = 0;
        }

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i; j < wordList.size(); ++j) {
                for (int k = 0; k < wordSize; ++k) {
                    if (wordList[i][k] != wordList[j][k]) {
                        ++differentCount;
                    }
                }

                if (differentCount == 1) {
                    adjacencyWordList[i + 1].push_back(wordList[j]);
                    adjacencyWordList[j + 1].push_back(wordList[i]);
                }

                wordIndexMapping[wordList[i]] = i + 1;
                differentCount = 0;
            }
        }

        for (const auto& pair : wordIndexMapping) {
            std::cout << pair.first << " : " << pair.second << '\n';
        }

        return bfs(wordList.size(), beginWord, endWord, wordIndexMapping, adjacencyWordList);
    }
};
