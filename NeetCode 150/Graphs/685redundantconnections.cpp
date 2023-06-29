class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par(edges.size() + 1);
        for (int i = 0 ; i < par.size(); i++) {
            par[i] = i;
        }
        vector<int> rank(edges.size() + 1,1);
        for (int i = 0 ; i < edges.size(); i ++) {
            if (!uni(edges[i][0],edges[i][1], par, rank)) {
                return edges[i];
            }
        }
        return {};
    }
public:
    int find(int x, vector<int>& par)  {
        int curr = x;
        while (par[curr] != curr) {
            par[curr] = par[par[curr]]; //hack for find. assign the father to the grandfather and then move to the father.
            curr = par[curr];
            // int temp = par[curr];
            // par[curr] = temp;
            // curr = temp;
        }
        return curr;
    }

public:
    bool uni(int x, int y, vector<int>& par, vector<int>& rank) {
        int p1 = find(x, par);
        int p2 = find(y, par);
        if (p1 == p2) {
            return false;
        } else {
            if (rank[p1]  >= rank[p2]) { //weighted union to make sure the smaller rank added to bigger rank!
                rank[p1] += rank[p2];
                par[p2] = p1;
            } else {
                rank[p2] += rank[p1];
                par[p1] = p2;
            }
        }
        return true;
    }


};