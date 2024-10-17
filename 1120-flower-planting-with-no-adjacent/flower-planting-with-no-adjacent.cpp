class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> vis(n, 0);
        vector<int> adj[n + 1];
        for (int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i - 1]==0) {
                int t=0;
                for (int j = 0; j < adj[i].size(); j++) {
                    int node = adj[i][j];
                    if (vis[node - 1]) {
                        t|=(1<<(vis[node - 1]-1));
                    }
                }
                // cout<<i<<" "<<t<<endl;
                for(int  k=0;k<4;k++){
                    if((t&(1<<k))==0){
                        vis[i-1]=k+1;
                        break;
                    }
                }
                // cout<<vis[i-1]<<endl;
            }
        }
        return vis;
    }
};