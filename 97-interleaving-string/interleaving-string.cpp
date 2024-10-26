class Solution
{
    public:
    int dp[101][101][201];
        bool helper(string s1, string s2, string s3, int x, int y, int z)
        {
            if (x >= s1.size() && y >= s2.size() && z == s3.size()) return 1;
            if(dp[x][y][z]!=-1) return dp[x][y][z];
            if (x < s1.size() && y < s2.size())
            {
                if (s1[x] == s3[z] && s2[y] == s3[z])
                    return dp[x][y][z]= helper(s1, s2, s3, x + 1, y, z + 1) ||
                        helper(s1, s2, s3, x, y + 1, z + 1);
                else if (s1[x] == s3[z])
                    return dp[x][y][z]= helper(s1, s2, s3, x + 1, y, z + 1);
                else if (s2[y] == s3[z])
                    return dp[x][y][z]= helper(s1, s2, s3, x, y + 1, z + 1);
            }
            else if (x < s1.size() && s1[x] == s3[z])
                return dp[x][y][z]= helper(s1, s2, s3, x + 1, y, z + 1);
            else if (y < s2.size() && s2[y] == s3[z])
                return dp[x][y][z]= helper(s1, s2, s3, x, y + 1, z + 1);
            return 0;
        }
    bool isInterleave(string s1, string s2, string s3)
    {
        memset(dp,-1,sizeof(dp));
        if (s1.size() + s2.size() != s3.size())
            return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
};