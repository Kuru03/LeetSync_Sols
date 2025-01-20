class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,pair<int,int>> map;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[mat[i][j]]={i,j};
            }
        }
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<arr.size();i++){
            pair<int,int> t=map[arr[i]];
            row[t.first]++;
            col[t.second]++;
            if(row[t.first]==m || col[t.second]==n ) return i;
        }
        return -1;

    }
};