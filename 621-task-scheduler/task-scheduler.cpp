class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> hm;
        for(int i = 0; i < tasks.size(); i++) {
            hm[tasks[i]]++;
        }

        for (auto num : hm) {
            pq.push({num.second, num.first});
        }
        int result = 0;

        while (pq.size() > 0) {
            if (pq.top().first == 1) {
                result += pq.size();
                break;
            }
            vector<pair<int,char>> temp;
            for (int i = 0; i < n + 1; i++) {
                if (pq.size() > 0) {
                    pair<int,char> fir = pq.top();
                    pq.pop();
                    temp.push_back(fir);
                }
                result++;
            }
            for(auto x : temp) {
                if(x.first>1) pq.push({x.first-1,x.second});
            }

        }
        return result;
    }
};