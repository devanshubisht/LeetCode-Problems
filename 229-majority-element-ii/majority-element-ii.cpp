class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> hm;
        
        for (int i = 0 ; i < size; i++) {
            hm[nums[i]]++;
        }
        vector<int> res;
        for (const auto& pair : hm) {
            if (pair.second > float(size)/3) {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

// naive solution is to have a ordered hashmap and then add. this would be o(n) o(1)

// 