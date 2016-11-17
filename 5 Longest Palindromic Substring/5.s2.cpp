class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();
        if (str_len<2) return s;
        
        int left = 0, right = 0, max_len = 1, max_left = 0;
        for (int start=0; start<str_len && str_len-start > str_len/2;) {
            left = right = start;
            while (right < str_len-1 && s[right] == s[right + 1]) {
                right++;
            }
            start = right + 1;
            while (right < str_len-1 && left > 0 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            int len = right - left + 1;
            if (len>max_len) {
                max_len = len;
                max_left = left;
            }
        }
        return s.substr(max_left, max_len);
    }
};