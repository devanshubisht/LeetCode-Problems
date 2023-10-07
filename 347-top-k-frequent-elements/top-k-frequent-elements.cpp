class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        
        vector<pair<int, int>> elements(map.begin(), map.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap(elements.begin(), elements.end());

        vector<int> res;
        for (int i = 0; i < k; i++) {
            pair<int, int> a = maxHeap.top();
            maxHeap.pop();
            res.push_back(a.first);
        }
        return res;
    }
};
