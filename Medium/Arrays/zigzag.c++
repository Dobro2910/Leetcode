class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> array(numRows, "");
        bool zigzag = false;
        int indexRow = 0;
        string returnString = "";

        if (numRows == 1) {
            return s;
        }

        for (int i = 0; i < s.size(); ++i) {
            if ((indexRow == 0 || indexRow == numRows - 1) && i != 0) {
                if (zigzag == false) {
                    zigzag = true;
                } else if (zigzag == true) {
                    zigzag = false;
                }
            }
            
            if (zigzag == false) {
                array[indexRow] += s[i];
                ++indexRow;
            } else if (zigzag == true) {
                array[indexRow] += s[i];
                --indexRow;
            }
        }

        for (int i = 0; i < array.size(); ++i) {
            returnString += array[i];
        }

        return returnString;
    }
};