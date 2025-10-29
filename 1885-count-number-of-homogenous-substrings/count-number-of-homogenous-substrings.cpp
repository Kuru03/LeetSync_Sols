#define ll long long
class Solution {
public:
    int countHomogenous(string s) {
        ll ans=0;
        ll n=s.size();
        ll mod=1e9+7;
        ll lastSeen=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[lastSeen]){
                ans+=(i-lastSeen)*(i-lastSeen+1)/2;
                ans%=mod;
                lastSeen=i;
            }
        }
        ans+=(n-lastSeen)*(n-lastSeen+1)/2;       
        return ans%=mod;
    }
};