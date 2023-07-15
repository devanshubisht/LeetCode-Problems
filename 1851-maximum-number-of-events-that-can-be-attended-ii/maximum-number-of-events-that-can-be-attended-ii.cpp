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

        int lo = index + 1, hi = events.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(events[mid][0] <= events[index][1]) lo = mid + 1;
            else hi = mid;
        }

        int c1 = events[index][2] + helper(events, lo, k-1, dp);
        int c2 = helper(events, index + 1, k, dp);

        return dp[index][k] = max(c1,c2);
    }

};

// int BS(int index,vector<vector<int>>&events,int value)
// {
//     int lo = index;
//     int hi = events.size()-1;
//     int req = -1;
//     while(hi>=lo)
//     {
//       int mid = lo+(hi-lo)/2;
//       if(events[mid][0] > value)
//       {
//         req = mid;
//         hi = mid-1;
//       }
//       else lo = mid+1;
//     }
//     return req;
// }
