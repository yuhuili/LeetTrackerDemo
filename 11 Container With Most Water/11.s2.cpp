class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = 0, c=height.size()-1;
        for (vector<int>::reverse_iterator it=height.rbegin(); it != height.rend(); ++it, c--) 
            m = max(*it * c, m);
        return m;
    }
};