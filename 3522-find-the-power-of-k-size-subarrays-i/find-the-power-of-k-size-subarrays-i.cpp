class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        vector<int> vec;
        for(int i=0;i<arr.size()-k+1;i++){
            int t=arr[i];
            for(int j=1;j<k;j++){
                // cout<<i<<" "<<i+j<<endl;
                int ind=i+j;
                if(arr[ind]==arr[ind-1]+1) t=arr[ind];
                else{ t=-1;break;}
            }
            vec.push_back(t);
        }
        return vec;
    }
};