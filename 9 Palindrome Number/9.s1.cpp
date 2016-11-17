class Solution {
public:
    int numDigits(long x) {
        return x > 0 ? (long) log10 (x) + 1 : 1;
    }

    bool isPalindrome(int x) {
        long xx = x;
        if (xx<0) xx = -xx;
        
        int n = numDigits(xx);
        //cout << "n:" << n << endl;
        int left = 0;
        int right = n-1;
        while (left<right) {
            int ld = ((long) (xx/(pow(10, n-left-1) ))) % 10;
            int rd = ((long) (xx/(pow(10, n-right-1)))) % 10;
            //cout << "checking ld:" << ld << " rd" << rd << endl;
            if (ld!=rd) return false;
            left++;
            right--;
        }
        return true;
    }
};