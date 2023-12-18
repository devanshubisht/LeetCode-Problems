class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size() - 1;
        int globalArea = 0;

        while (l < r) {
            int min_val = min(height[l], height[r]);
            globalArea = max(globalArea, min_val * (r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return globalArea;
        
    }
};