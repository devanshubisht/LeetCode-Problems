class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 0, j = 0 , zero = 1;
        for(int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 0) {
                zero--;
            }
            while (zero < 0) {
                if (nums[k] == 0){
                    zero++;
                }
                k++;
            }
            j = max(j, i - k + zero);
        }
        if (zero == 1) {
            return j-1;
        }
        
        return j;
    }
};

//   1 0 1 1 1 0 1
//   0 1 2 3 4 5 6


// 1111 0 11