class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0 ; i < nums.size() -1; i++) {
            if (nums[i] == 0) {
                int x = i -1;
                while (x >= 0 ) {
                    if(x + nums[x] > i) {
                        break;
                    }
                    x--;
                }
                if (x==-1) return false;
            }
        }
        return true;
    }
};