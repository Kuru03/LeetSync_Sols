#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        ll ans=0,n=arr.size();
        vector<ll> vec(n,0);
        vec[0]=arr[0];
        unordered_map<int,int> map;
        for(int i=1;i<n;i++){
            vec[i]+=vec[i-1]+arr[i];
        }
        int l=0,r=0;
        while(r<n){
            if(map.count(arr[r])!=0 && l<=map[arr[r]]){
                l=map[arr[r]]+1;
            }
            map[arr[r]]=r;
            if((r-l+1)>=k){
                l=r-k+1;
                ans=max(ans,(ll)(vec[r]-vec[l]+arr[l]));
            }
            
            r++;   
        }
        return ans;
    }
};