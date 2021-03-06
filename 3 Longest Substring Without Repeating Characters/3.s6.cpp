class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length()==0) return 0;
    
    int a=0;
    int b=0;
    int longest=1;
    unordered_map<char, int> seenMap;
    seenMap[s[a]]++;
    int slen = s.length()-1;
    while (b!=slen) {
      b++;
      char bval = s[b];
      if (seenMap[bval]!=0) {
        longest = max(longest, b-a);
        while (s[a]!=bval) {
          seenMap[s[a]]--;
          a++;
        }
        a++;
      }
      else {
        seenMap[bval]++;
      }
    }
    longest = max(longest, b-a+1);
    return longest;
  }
};