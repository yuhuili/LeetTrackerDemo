class Solution {
public:
    string longestPalindrome(string s) {
        int sl=s.length();
        
        int a=0;
        int l=sl;
        int b=l-1;
        while(true) {
            while (b<sl) {
                if(isPalindrome(s, a, b)) {
                    return s.substr(a, l);
                }
                a++;
                b++;
            }
            a=0;
            l--;
            b=l-1;
        }
    }
    
    bool isPalindrome(string s, int begin, int end) {
        int a=begin;
        int b=end;
        while(a<=b) {
            if (s[a]!=s[b]) return false;
            a++;
            b--;
        }
        return true;
    }
};