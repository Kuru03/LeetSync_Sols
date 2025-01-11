
class disJointSet {
public:
    map<pair<int, int>, int> size;
    map<pair<int, int>, pair<int, int>> par;
    disJointSet() {}

    pair<int, int> findUPar(pair<int, int> u) {
        if (par.count(u) == 0)
            return u;
        return par[u] = findUPar(par[u]);
    }

    int findSize(pair<int, int> u) {
        pair<int, int> pt = findUPar(u);
        if (size.count(pt) == 0)
            return 1;
        return size[pt];
    }

    void unionBySize(pair<int, int> u, pair<int, int> v) {
        pair<int, int> ultPar_u = findUPar(u);
        pair<int, int> ultPar_v = findUPar(v);
        if (size.count(ultPar_u) == 0)
            size[ultPar_u] = 1;
        if (size.count(ultPar_v) == 0)
            size[ultPar_v] = 1;

        if (ultPar_u == ultPar_v)
            return;
        if (size[ultPar_u] > size[ultPar_v]) {
            par[ultPar_v] = ultPar_u;
            size[ultPar_u] += size[ultPar_v];

        } else {
            par[ultPar_u] = ultPar_v;
            size[ultPar_v] += size[ultPar_u];
        }
        return;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        disJointSet ds;
        int arrx[4] = {1, 0, -1, 0};
        int arry[4] = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << i << " " << j << "  knjk" << endl;

                if (grid[i][j] == 0) {
                    continue;
                }
                for (int t = 0; t < 4; t++) {
                    int X = i+arrx[t];
                    int Y = j+arry[t];
                    if (X >= n || Y >= m || X < 0 || Y < 0) {
                        continue;
                    }
                    if (grid[X][Y] == 1) {
                        ds.unionBySize({i, j}, {X, Y});
                    }
                }
            }
        }
        int cnt = 0;
        // cout << "knjk" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << i << " " << j << "  isj" << endl;
                if (grid[i][j] == 1) {
                    cnt = max(cnt, ds.findSize({i, j}));
                    continue;
                }
                int tempCnt = 1;
                map<pair<int, int>, int> tempPar;
                for (int t = 0; t < 4; t++) {
                    int X = i+arrx[t];
                    int Y = j+arry[t];
                    if (X >= n || Y >= m || X < 0 || Y < 0) {
                        continue;
                    }
                    // cout<<X<<" "<<Y<<" "<<grid[X][Y]<<endl;
                    if (grid[X][Y] == 1) {
                        pair<int, int> pt = ds.findUPar({X, Y});
                        // cout<<pt.first<<" "<<pt.second<<endl;
                        if (tempPar.count(pt) == 0) {
                            // cout<<X<<" "<<Y<<endl;
                            tempCnt += ds.findSize({X, Y});
                            tempPar[pt]++;
                        }
                    }
                }
                // cout<<tempCnt<<endl;
                cnt = max(cnt, tempCnt);
            }
        }
        return cnt;
    }
};