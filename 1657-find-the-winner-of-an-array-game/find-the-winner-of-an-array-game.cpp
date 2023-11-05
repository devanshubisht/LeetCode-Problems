class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        vector<int> maxArray (arr.size());
        maxArray[0] = arr[0];
        for (int i = 1 ; i < arr.size() ; i++) {
            maxArray[i] = max(maxArray[i - 1], arr[i]);
        }
        int curr = 0;
        for (int i = 1 ; i < maxArray.size(); i++) {
            if (maxArray[i] == maxArray[i-1]) {
                curr++;
                if (curr == k) {
                    return maxArray[i];
                }
            } else {
                curr = 1;
                if (curr == k) {
                    return maxArray[i];
                }
            }
        }
        return maxArray[arr.size() -1];
    }
};