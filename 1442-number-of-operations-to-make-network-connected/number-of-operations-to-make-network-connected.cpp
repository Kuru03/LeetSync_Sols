class disJointSet{
    public:
    vector<int> rank;
    vector<int> size;
    vector<int> par;
    disJointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int findUPar(int u){
        if(par[u]==u) return u;
        return par[u]=findUPar(par[u]);
    }
    void unionBySize(int u,int v){
        int ultPar_u=findUPar(u);
        int ultPar_v=findUPar(v);
        if(ultPar_u==ultPar_v) return;
        if(size[ultPar_u]>size[ultPar_v]){
            par[ultPar_v]=ultPar_u;
            size[ultPar_u]+=size[ultPar_v];

        }
        else{
            par[ultPar_u]=ultPar_v;
            size[ultPar_v]+=size[ultPar_u];
        }
        return;
    }
    void unionByRank(int u,int v){
        int ultPar_u=findUPar(u);
        int ultPar_v=findUPar(v);
        if(ultPar_u==ultPar_v) return;
        if(rank[ultPar_u]>rank[ultPar_v]){
            par[ultPar_v]=ultPar_u;

        }
        else if(rank[ultPar_u]<rank[ultPar_v]){
            par[ultPar_u]=ultPar_v;
        }
        else{
            par[ultPar_v]=ultPar_u;
            rank[ultPar_u]++;
        }
        return;
    }

};


class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
       disJointSet ds(n);
        if(connections.size()<n-1) return -1;
        for(int i=0;i<connections.size();i++){
            ds.unionByRank(connections[i][0],connections[i][1]);
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int par=ds.findUPar(i);
            // cout<<i<<" "<<par<<endl;
            mp[par]++;
        }
        return mp.size()-1;
    }
};