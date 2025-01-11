
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, int> map;
        disJointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (map.count(accounts[i][j]) == 0) {
                    map[accounts[i][j]] = i;
                } else {
                    ds.unionByRank(i, map[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> vec;
        vector<int> visit(n,-1);

        map.clear();
        for (int i = 0; i < n; i++) {
            int par = ds.findUPar(i);
            // cout<<i<<" "<<par<<" "<<visit[par]<<endl;
            if (visit[par]!=-1) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    if( map.count(accounts[i][j])==0){
                        vec[visit[par]].push_back(accounts[i][j]);
                        map[accounts[i][j]]=par;
                    }
                   
                }
            } 
            else {
                
                vector<string> trav;
                for(int j=0;j<accounts[i].size();j++) {
                     if( map.count(accounts[i][j])==0 ||  map[accounts[i][j]]!=par){
                        trav.push_back(accounts[i][j]);
                        map[accounts[i][j]]=par;
                    }
                }
                vec.push_back(trav);
                visit[par] = vec.size() - 1;
            }
        }
        for(int i=0;i<vec.size();i++){
            sort(vec[i].begin()+1,vec[i].end());
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
};