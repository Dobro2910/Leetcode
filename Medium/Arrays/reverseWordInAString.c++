#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        vector<string> stringArray;
        vector<string> reverseStringArray;

        string word;
        stringstream seperateString(s);
        while (getline(seperateString, word, ' ')) {
            if (word.empty()) {
                continue;
            } else {
                stringArray.push_back(word);
            }
        }

        string reverseString = "";
        for (int i = stringArray.size() - 1; i >= 0; --i) {
            reverseString += stringArray[i];

            if (i == 0) {
                continue;
            } else {
                reverseString += " ";
            }
        }

        return reverseString;
    }
};