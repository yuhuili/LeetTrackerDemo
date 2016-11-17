class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = 0, l = 0, r = height.size()-1;
        while (l < r) {
            m = max(m, (r - l) * min(height[l], height[r]));
            height[l] < height[r] ? l++ : r--;
        }
        return m;
    }
};