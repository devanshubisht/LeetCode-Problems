class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> result(amount + 1, amount + 1);
        result[0] = 0;
        for (int i = 1; i <= amount; i++ ) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j]<= i) {
                    result[i] = min(result[i], 1 + result[i-coins[j]]);
                }
            }
        }
        return result[amount] > amount ? -1 : result[amount];
    }
};

// [1, 2, 5]
// count 0

// take the largest , if == amount return count

// for int i in range (3)
//  take 
//  dfs
//  remove

//       0
//     5 2 1
// 55 52 22 21 11 

// memoise the sum = the min take