class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequenceHelper(int ind1, int ind2, string text1,string text2) {
        if (ind1 == text1.size() || ind2 == text2.size()) {
            return 0;
        }
        int ans = 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2]) {
            ans = 1 + longestCommonSubsequenceHelper(ind1 + 1, ind2 + 1, text1,text2);
        } else {
            int take1 =
                longestCommonSubsequenceHelper(ind1 + 1, ind2, text1, text2);
            int take2 =
                longestCommonSubsequenceHelper(ind1, ind2 + 1, text1, text2);
            ans = max(take1, take2);
        }
        return dp[ind1][ind2] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        // return longestCommonSubsequenceHelper(0, 0, text1, text2);
        int n = text1.size(), m = text2.size();
        // for (int i = 0; i < n; i++)
        //     dp[i][m] = 1;
        // for (int i = 0; i < m; i++)
        //     dp[n][i] = 1;
        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) { 
                int ans = 0;
                if (text1[ind1] == text2[ind2]) {
                    ans = 1 + dp[ind1 + 1][ind2 + 1];
                } else {
                    int take1 = dp[ind1 + 1][ind2];
                    int take2 = dp[ind1][ind2 + 1];
                    ans = max(take1, take2);
                }
                dp[ind1][ind2]=ans;
            }
        }
        // for (int ind1 = n; ind1 >= 0; ind1--) {
        //     for (int ind2 = m; ind2 >= 0; ind2--) {
        //         cout << dp[ind1][ind2] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][0];
    }
};