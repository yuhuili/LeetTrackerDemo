class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int s = nums.size();
        if (s==0) return 0;
        
        int front = 0;
        int temp;
        
        for (vector<int>::iterator it = nums.begin(); it!=nums.end(); it++) {
            temp = *it;
            if (temp!=nums[front]) {
                nums[++front]=temp;
            }
        }
        
        return ++front;
        
    }
};