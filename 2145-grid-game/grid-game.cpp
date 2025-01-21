class Solution {
public:
    // map<pair<int,int>,pair<int,int>> map;
    // int dp[2][50005];
    // long long gridGameHelper(int x,int y,vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     long long down=0,right=0;
    //     if(x==n-1 &&  y==m-1) return grid[x][y];
    //     if(dp[x][y]!=-1) return dp[x][y];
    //     // cout<<x<<" "<<y<<endl;

    //     if(x!=n-1){
    //         down=gridGameHelper(x+1,y,grid);
    //     }
    //     if(y!=m-1){
    //         right=gridGameHelper(x,y+1,grid);
    //     }
    //     // cout<<x<<" "<<y<<" "<<down<<" "<<right<<endl;;
    //     if(down>right){
    //         map[{x,y}]={x+1,y};
    //     }
    //     else{
    //         map[{x,y}]={x,y+1};
    //     }
    //     return dp[x][y]= max(down,right)+grid[x][y];
    // }
    long long gridGame(vector<vector<int>>& grid) {
        long long ans=0;
        int m=grid[0].size();
        vector<vector<long long>> dp(2,vector<long long>(m,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=grid[i][j];
            }
        }

        for(int i=m-2;i>=0;i--){
            dp[0][i]+=dp[0][i+1];
        }
        for(int i=1;i<m;i++){
            dp[1][i]+=dp[1][i-1];
        }
        // long long ans=0;
        if(m>1) ans=min(dp[0][1],dp[1][m-2]);
        for(int i=1;i<m-1;i++){
            long long t=max(dp[0][i+1],dp[1][i-1]);
            ans=min(ans,t);
        }
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};

// [108,98,95,85,68,66,54,39,22,18]
// [99,79,69,56,42,27,22,20,17,3]