class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return helper(events,0,k,dp);
    }

    int helper(vector<vector<int>>& events, int index, int k, vector<vector<int>>& dp) {
        if (index >= events.size() || k == 0) {
            return 0;
        }

        if (dp[index][k] != -1) {
            return dp[index][k];
        }

        vector<int> temp = {events[index][1],INT_MAX,INT_MAX};
        int next = upper_bound(events.begin()+index+1, events.end(), temp)-events.begin();


        int c1 = events[index][2] + helper(events, next, k-1, dp);
        int c2 = helper(events, index + 1, k, dp);

        return dp[index][k] = max(c1,c2);
    }
    // int bs(vector<vector<int>>& events, int index) {
    //     int i = 0 ;
    //     int j = events.size() -1;
    //     while (i <=j) {
    //         int mid = i + (j-i)/2;
    //         int val = events[mid][0];
    //         if (index<val) {
    //             j = mid -1;
    //         }
    //         else if (index > val) {
    //             i = mid+ 1;
    //         } else {
    //             return mid;
    //         }
    //     }
    //     return -1;
    // }
};