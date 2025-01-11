class Solution {
public:
    int dp[50002][2];
    int maxCooldownProfit(int ind,int buy,vector<int> & prices,int fee){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans=0;
        if(buy){
            ans=maxCooldownProfit(ind+1,0,prices,fee)-prices[ind]-fee;
        }
        else{
            ans=maxCooldownProfit(ind+1,1,prices,fee)+prices[ind];
        }
        int skip=maxCooldownProfit(ind+1,buy,prices,fee);
        return dp[ind][buy]=max(ans,skip);
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return maxCooldownProfit(0,1,prices,fee);
        
    }

};