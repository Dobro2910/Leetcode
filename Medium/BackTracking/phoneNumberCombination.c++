class Solution {
public:
    void helper(vector<vector<char>>& choosenVector, set<string>& returnSet, 
                string currentString, int depth, int maxDepth) 
    {
        vector<char> currentVector = choosenVector[depth];
        
        for (int i = 0; i < currentVector.size(); ++i) {
            string tempString = currentString + currentVector[i];

            if (depth != maxDepth) {
                helper(choosenVector, returnSet, tempString, depth + 1, maxDepth);
            } else {
                returnSet.insert(tempString);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> phoneMapping;

        char ch = '0';
        for (int i = 2; i < 10; ++i) {
            switch (i) {
                case 2:
                    phoneMapping.insert({'2', {'a','b','c'}});
                    break;
                case 3:
                    phoneMapping.insert({'3', {'d','e','f'}});
                    break;
                case 4:
                    phoneMapping.insert({'4', {'g','h','i'}});
                    break;
                case 5:
                    phoneMapping.insert({'5', {'j','k','l'}});
                    break;
                case 6:
                    phoneMapping.insert({'6', {'m','n','o'}});
                    break;
                case 7:
                    phoneMapping.insert({'7', {'p','q','r','s'}});
                    break;
                case 8:
                    phoneMapping.insert({'8', {'t','u','v'}});
                    break;
                case 9:
                    phoneMapping.insert({'9', {'w','x','y','z'}});
                    break;
            }
        }

        vector<vector<char>> choosenVector;
        for (int i = 0; i < digits.size(); ++i) {
            choosenVector.push_back(phoneMapping[digits[i]]);
        }
        
        set<string> returnSet;
        string currentString = "";

        // maxDepth should be digits.size() - 1 if zero-indexed, but keeping your logic
        helper(choosenVector, returnSet, currentString, 0, digits.size() - 1);

        vector<string> returnResult;
        for (auto& s : returnSet) {
            returnResult.push_back(s);
        }

        return returnResult;
    }
};
