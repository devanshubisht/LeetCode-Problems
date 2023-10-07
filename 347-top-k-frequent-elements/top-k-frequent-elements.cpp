class Solution {
public:

    struct compare {
        bool operator()( pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for (int i = 0 ; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minheap;

        vector<int> res;
        for (const auto& firs: map) {
            minheap.push(firs);
            if (minheap.size() > k) {
                minheap.pop();
            }
        }
        for (int i =0 ; i < k; i++) {
            res.push_back(minheap.top().first);
            minheap.pop();
        }
        return res;
    }
};