class Solution {
public:
    class disJointSet {
        public:
        vector<int> rank;
        vector<int> size;
        vector<int> par;
        disJointSet(int n) {
            par.resize(n + 1);
            rank.resize(n + 1, 0);

            for (int i = 0; i <= n; i++)
                par[i] = i;
        }
        int findUPar(int u) {
            if (par[u] == u)
                return u;
            return par[u] = findUPar(par[u]);
        }

        void unionByRank(int u, int v) {
            int ultPar_u = findUPar(u);
            int ultPar_v = findUPar(v);
            if (ultPar_u == ultPar_v)
                return;
            if (rank[ultPar_u] > rank[ultPar_v]) {
                par[ultPar_v] = ultPar_u;

            } else if (rank[ultPar_u] < rank[ultPar_v]) {
                par[ultPar_u] = ultPar_v;
            } else {
                par[ultPar_v] = ultPar_u;
                rank[ultPar_u]++;
            }
            return;
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        disJointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    ds.unionByRank(i, j);
                }
            }
        }
        int ans = 0;
        map<int, int> map;
        for (int i = 0; i < n; i++)
            map[ds.findUPar(i)]++;
        return n - map.size();
    }
};