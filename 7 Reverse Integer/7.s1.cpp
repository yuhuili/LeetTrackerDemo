class Solution {
public:
    int reverse(int x) {
        int negative=false;
        if (x<0) {
            negative=true;
            x=-x;
        }
        
        int num_digits = GetNumberOfDigits (x);
        long long result = 0;
        for (int i=0;i<num_digits;i++) {
            result += ((int)(x/pow(10, i)))%10 * pow(10, num_digits-i-1);
        }
        
        if (result > INT_MAX) result=0;
        
        if (negative) return -result;
        return result;
        
    }
    
    int GetNumberOfDigits (int i)
    {
        return i > 0 ? (int) log10 ((double) i) + 1 : 1;
    }
};