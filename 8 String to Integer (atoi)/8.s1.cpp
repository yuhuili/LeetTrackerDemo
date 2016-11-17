class Solution {
public:
    int myAtoi(string str) {
                bool stillWhiteSpaces = true;
        bool negative = false;
    
        long result = 0;
    
        for (int i=0, len=str.length(); i<len; i++) {
            if (stillWhiteSpaces) {
                if (str[i]!=' ') {
                    stillWhiteSpaces=false;
                    if (str[i]=='+' || str[i]=='-') {
                        if (str[i]=='-') negative = true;
                    }
                    else if (str[i]-'0'>=0 && str[i]-'0'<=9) {
                        // is digit
                        result = result * 10 + (str[i]-'0');
                    }
                    else {
                        // invalid
                        return 0;
                    }
                }
            }
            else {
                if (str[i]-'0'>=0 && str[i]-'0'<=9) {
                    // is digit
                    result = result * 10 + (str[i]-'0');
                }
                else {
                    // stop
                    break;
                }
            }
        }
    
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
    
        return result;
    }
};