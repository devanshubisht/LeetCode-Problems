class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> lengths;
        int result=1;
        for (int i = arr.size() -1  ; i >=  0 ; i--) {
            if (lengths.find(arr[i] + difference) != lengths.end()) {
                lengths[arr[i]] = lengths[arr[i] + difference] + 1;
            } else {
                lengths[arr[i]] = 1;
            }
            result = max(result, lengths[arr[i]]);
        }
        return result;
    }
};
