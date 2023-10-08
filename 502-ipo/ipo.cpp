class Solution {
public:
    struct compare {
        bool operator()(pair<int,int>& a , pair<int,int>&b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            else {
                return a.first < b.first;
            }
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for (int i = 0 ; i < profits.size() ; i++) {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(), v.end(), compare());

        priority_queue<int> maxProfits;
        int latestIndex = check(v, 0, maxProfits, w);

        int numDone = 0;
        while ( numDone < k && !maxProfits.empty()) {
            int profit = maxProfits.top();
            w+= profit;

            maxProfits.pop();
            latestIndex = check(v, latestIndex, maxProfits, w);
            numDone++;
        }
        return w;
    }

    int check(vector<pair<int,int>>& v, int i, priority_queue<int>& maxProfits, int w) {
        while (i < v.size() && v[i].first <= w) {
            maxProfits.push(v[i].second);
            i++;
        }
        return i;
    }

};
