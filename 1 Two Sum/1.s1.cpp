class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int head=0;
    int tail=nums.size()-1;
    vector<int> result;
    vector<int> sortedNums;
    sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    while (head < tail) {
      if (sortedNums[head]+sortedNums[tail]==target) {
        break;
      }
      else if (sortedNums[head]+sortedNums[tail]>target) {
        tail--;
      }
      else {
        head++;
      }
    }
    
    bool foundA=false;
    bool foundB=false;
    int headValue=nums[head];
    int tailValue=nums[tail];
    for (int i=0; i<nums.size(); i++) {
      if (sortedNums[i]==headValue) {
        result.push_back(i);
        foundA=true;
      }
      else if (sortedNums[i]==tailValue) {
        result.push_back(i);
        foundB=true;
      }
      
      if (foundA==true&&foundB==true) break;
    }
    
    return result;
    }
};