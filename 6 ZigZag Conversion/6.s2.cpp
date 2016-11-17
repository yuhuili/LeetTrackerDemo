class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
    
        int a, b, len=s.length();
    
        string r = "";
    
        for (int i=0; i<numRows; i++) {
            a=(numRows-i-1)*2;
            b=i*2;
            int pos=i;
        
            if (pos<len) {
                r+=s[pos];
            }
            while(true) {
                pos+=a;
                if(pos>=len) break;
                if (a) r+=s[pos];
                pos+=b;
                if(pos>=len) break;
                if (b) r+=s[pos];
            }
        }
    
        return r;
    }
};