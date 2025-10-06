class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int total = 0;
        int sign = 1;
        string numStr = "";

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // isdigit check if c is a char 0 - 9
            if (isdigit(c)) {
                numStr += c;  // build the number string
            } else if (c == '+' || c == '-') {
                if (!numStr.empty()) {
                    total += sign * stoi(numStr);
                    numStr = "";
                }
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(total);
                st.push(sign);
                total = 0;
                sign = 1;
            } else if (c == ')') {
                if (!numStr.empty()) {
                    total += sign * stoi(numStr);
                    numStr = "";
                }
                int prevSign = st.top(); st.pop();
                int prevTotal = st.top(); st.pop();
                total = prevTotal + prevSign * total;
            }
        }

        // the for loop previously might not have added or subtracted the last number in the string, 
        // this is to add/subtract the last number
        if (!numStr.empty()) {
            total += sign * stoi(numStr);
        }

        return total;
    }
};
