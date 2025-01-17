class Solution {
public:
    vector<int> order;
    vector<int> preOrder;
    vector<vector<int>> criticalEdges;
    int cnt=1;

    void DFS(int root,vector<vector<int>>&adj,int par){
        int rootOrder=order[root];
        int rootPreOrder=preOrder[root];
        vector<int> traversed;

        for(int i=0;i<adj[root].size();i++){
            int child=adj[root][i];
            int childOrder=order[child];
            int childPreOrder=preOrder[child];
            if(child==par) continue;
            if(childOrder==-1){
                order[child]=cnt+1;
                preOrder[child]=cnt+1;
                cnt++;
                DFS(child,adj,root);
                traversed.push_back(child);
            }
            else{

                rootPreOrder=min(rootPreOrder,childPreOrder);
            }
        }
        preOrder[root]=rootPreOrder;
        for(int i=0;i<traversed.size();i++){
            int child=traversed[i];
            int childOrder=order[child];
            int childPreOrder=preOrder[child];
            preOrder[root]=min(preOrder[root],childPreOrder);
            if(childPreOrder>rootOrder){
                criticalEdges.push_back({root,child});
            }
        }
        return;

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int t=connections.size();
        vector<vector<int>> adj(n);
        order.resize(n,-1);
        preOrder.resize(n,-1);
        for(int i=0;i<t;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        preOrder[0]=1;
        order[0]=1;
        DFS(0,adj,-1);
        return criticalEdges;

    }
};