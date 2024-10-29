class Solution {
public:
    int dp[1001][1001];
    int n, m;
    bool check(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return 0;
        return 1;
    }
    int maxMovesCalculator(vector<vector<int>>& grid, int x, int y) {

        if (dp[x][y] != -1)
            return dp[x][y];

        // cout<<x<<" "<<y<<endl;
        int upperRight = 0, lowerRight = 0, right = 0;
        if (check(x - 1, y + 1) && grid[x][y] < grid[x - 1][y + 1]) {
            upperRight =1+ maxMovesCalculator(grid, x - 1, y + 1);
        }
        if (check(x + 1, y + 1) && grid[x][y] < grid[x + 1][y + 1]) {
            lowerRight =1+ maxMovesCalculator(grid, x + 1, y + 1);
        }
        if (check(x, y + 1) && grid[x][y] < grid[x][y + 1]) {
            right =1+ maxMovesCalculator(grid, x, y + 1);
        }
        

        return dp[x][y] =  max({upperRight, lowerRight, right});
    }

    int maxMoves(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t = maxMovesCalculator(grid, i, 0);
            ans = max(ans, t);
        }
        return ans;
    }
};