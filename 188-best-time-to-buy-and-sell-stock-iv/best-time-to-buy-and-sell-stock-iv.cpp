class Solution {
private:
    vector<int> prices;
    // memo[i][k_left][state] -> best profit from day i..n-1
    // state: 0 = flat, 1 = holding long, 2 = holding short
    vector<vector<vector<long long>>> memo;
    vector<vector<vector<char>>> seen;
    static constexpr long long NEG = (long long)-4e18;

    long long dp(int i, int k_left, int state, bool can_ss) {
        int n = (int)prices.size();

        // base cases
        if (i == n) return (state == 0 ? 0 : NEG);
        if (k_left < 0) return NEG;

        if (seen[i][k_left][state]) return memo[i][k_left][state];
        seen[i][k_left][state] = 1;

        long long best = NEG;
        int p = prices[i];

        if (state == 0) {                   // currently flat
            // skip today
            best = max(best, dp(i + 1, k_left, 0, can_ss));
            // open long (consume one trade)
            if (k_left > 0)
                best = max(best, dp(i + 1, k_left - 1, 1, can_ss) - (long long)p);
            // open short (consume one trade) if allowed
            if (can_ss && k_left > 0)
                best = max(best, dp(i + 1, k_left - 1, 2, can_ss) + (long long)p);

        } else if (state == 1) {            // holding long
            // keep holding
            best = max(best, dp(i + 1, k_left, 1, can_ss));
            // sell -> flat (closing does NOT change k_left)
            best = max(best, dp(i + 1, k_left, 0, can_ss) + (long long)p);

        } else {                            // state == 2, holding short
            if (!can_ss) return memo[i][k_left][state] = NEG; // safety
            // keep short
            best = max(best, dp(i + 1, k_left, 2, can_ss));
            // buy back -> flat
            best = max(best, dp(i + 1, k_left, 0, can_ss) - (long long)p);
        }

        return memo[i][k_left][state] = best;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        (*this).prices = prices;
        int n = (int)prices.size();
        if (n == 0 || k == 0) return 0;

        memo.assign(n, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));
        seen.assign(n, vector<vector<char>>(k + 1, vector<char>(3, 0)));

        // For Task 1–5 (short-selling allowed):
        return dp(0, k, 0, false);
    }
};

