class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int MOD = 1e9 + 7;

        unordered_map<int,int> hm;

        for (int i = 0 ; i < arr.size(); i++) {
            hm[arr[i]]++;
            for (int j = 0 ; j < i ; j++) {
                if (arr[i] % arr[j] == 0) {
                    int div = arr[i] / arr[j];
                    if (hm.count(div) > 0) {
                        hm[arr[i]] = (hm[arr[i]] + static_cast<long long>(hm[arr[j]]) * hm[div]) % MOD;

                    }
                }
            }
        }
        int result = 0;
        for (const auto& key: hm) {
            result = static_cast<long long>(result + key.second) %  MOD;
        }

        return result;
        
    }
};

// sort the array 

// divide with the prev and if have in hashmap then it works

// 2 5 10 20 40 100