class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int s = nums.size();
        if (s==0) return 0;
        
        int front = 0, temp, i;
        
        for (i=1; i<s;i++) {
            temp = nums[i];
            if (temp!=nums[front]) {
                nums[++front]=temp;
            }
        }
        
        return ++front;
        
    }
};