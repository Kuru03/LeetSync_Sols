class Solution {
public:
    int minChanges(string s) {
        int ans=0,cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            // cout<<cnt<<" "<<i<<" "<<ans<<endl;
            if(i%2==0){
                if(cnt==1) ans++;
                cnt=(s[i]-'0');
            }
            else{
                cnt+=(s[i]-'0');
            }
        }
        ans+=(cnt%2);
        return ans;
    }
};