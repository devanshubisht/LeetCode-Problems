class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if ((arr[mid]> arr[mid+1]) && (arr[mid-1]< arr[mid])) {
                ans = mid;
                break;
            } else if (arr[mid] < arr[mid+1]){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
