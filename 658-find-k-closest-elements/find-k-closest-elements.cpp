class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        auto it = std::lower_bound(arr.begin() , arr.end(), x);
        int i = std::distance(arr.begin(), it);

        int left = i-1;
        int right = i;

        while (result.size() != k) {

            if (right >= arr.size() || left >= 0  && abs(arr[left] - x) <= abs(arr[right] - x)) {
                result.push_back(arr[left]);
                left--;
            } else {
                result.push_back(arr[right]);
                right++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};