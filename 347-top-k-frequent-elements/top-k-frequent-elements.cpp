class Solution {
public:

    struct compare {
        bool operator()( pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for (int i = 0 ; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        vector<pair<int, int>> elements(map.begin(), map.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare > pq(elements.begin(), elements.end());

        vector<int> res;
        for (int i = 0 ; i < k ; i++) {
            pair<int,int> a = pq.top();
            pq.pop();
            res.push_back(a.first);
        }
        return res;

    }
};