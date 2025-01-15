class Solution {
public: 
    int dp[201][201];
    int arrx[4]={1,0,-1,0};
    int arry[4]={0,1,0,-1};
    int longestIncreasingPathHelper(int x,int y,vector<vector<int>>& visit,vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(dp[x][y]!=-1) return dp[x][y];
        visit[x][y]=1;
        int ans=0;
        for(int i=0;i<4;i++){
            int X=x+arrx[i];
            int Y=y+arry[i];
            if(X<0 || Y<0 || X>=n || Y>=m || visit[X][Y]==1 ||  grid[x][y]>=grid[X][Y] ) continue;
            int tempRoute=longestIncreasingPathHelper(X,Y,visit,grid)+1;
            ans=max(ans,tempRoute);
        }
        visit[x][y]=0;
        return dp[x][y]=max(ans,1);        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size();
        memset(dp,-1,sizeof(dp));
        int m=matrix[0].size();
        vector<vector<int>> visit (n,vector<int>(m,0));
        // memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nodeAns=longestIncreasingPathHelper(i,j,visit,matrix);
                // cout<<nodeAns<<endl;
                ans=max(ans,nodeAns);
            }
        }
        return ans;
        
    }
};