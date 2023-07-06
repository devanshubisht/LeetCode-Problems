class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 1, temp =0;
     for (int i = 0 ; i < n - 1 ; i++) {
         temp = x;
         x = x + y;
         y = temp;
     }
     return x;
        
    }
};