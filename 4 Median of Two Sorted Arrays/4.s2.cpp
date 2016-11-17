class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int c1=0;
    int c2=0;
    int nums1_size = nums1.size();
    int nums2_size = nums2.size();
    while (c1!=nums1_size&&c2!=nums2_size) {
      if (nums1[c1] < nums2[c2]) {
        merged.push_back(nums1[c1]);
        c1++;
      }
      else {
        merged.push_back(nums2[c2]);
        c2++;
      }
    }
    
    while (c1!=nums1_size) {
      merged.push_back(nums1[c1]);
      c1++;
    }
    
    while (c2!=nums2_size) {
      merged.push_back(nums2[c2]);
      c2++;
    }
    
    int totalElements = nums1_size + nums2_size;
    if (totalElements%2==0) {
      return double(merged[totalElements/2-1]+merged[totalElements/2])/2;
    }
    else {
      return double(merged[totalElements/2]);
    }
  }
};