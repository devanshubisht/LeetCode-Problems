class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size() -1;
        for (int i = 0; i < n ; i++) {
            weights[i] += weights[i+1];
        }
        weights.pop_back();

        sort(weights.begin(), weights.end());
        long long res = 0;
        for (int i = 0 ; i < k-1; i++) {
            res += - weights[i] + weights[n - 1 - i];
        }
        return res;
    }
};