class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0;
        for (vector<int>::iterator it = nums.begin(); it!=nums.end(); it++) {
            i ^= (*it);
        }
        
        return i;
    }
};