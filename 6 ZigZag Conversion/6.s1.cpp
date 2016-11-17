class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v;
        
        for (int k=0; k<numRows; k++) {
            v.push_back("");
        }
        
        int i=0, r=0, c=0, len=s.length();
        
        while (i<len) {
            while (r<numRows) {
                if (c%2==0 || r%2==1) {
                    v[r] += s[i];
                    i++;
                }
                r++;
            }
            r=0;
            c++;
        }
        
        string os="";
        for (vector<string>::iterator it=v.begin(); it!=v.end(); it++) {
            os+=*it;
        }
        
        return os.substr(0,s.length());
    }
};