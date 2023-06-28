class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq1, pq2;
        int count = 0;
        int i = 0;
        int j = costs.size() - 1;
        long long res = 0;
        while (count < k)
        {
            while (pq1.size() < candidates && i <= j)
            {
                pq1.push(costs[i++]);
                // the <= and >= is important because there could be overlap. the pointer moves after addition and may not allow the next entry of the item.
            }
            while (pq2.size() < candidates && j >= i)
            {
                pq2.push(costs[j--]);
            }
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (a <= b)
            {
                res += a;
                pq1.pop();
            }
            else
            {
                res += b;
                pq2.pop();
            }
            count++;
        }
        return res;
    }
};