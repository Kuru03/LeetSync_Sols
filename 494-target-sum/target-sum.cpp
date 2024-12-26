class Solution {
public:
 int f(vector<int>& nums, int target) {
     vector<int> prev(target+1,0),cur(target+1,0);
     if(nums[0]<=target) prev[nums[0]]=1;
     if(nums[0]==0) prev[0]+=1;
     else prev[0]=1;
     for(int i=1;i<nums.size();i++){
        // prev[0]=1;
        for(int k=0;k<=target;k++){
            cur[k]=prev[k];
            if(k>=nums[i]) cur[k]+=prev[k-nums[i]];
        }
        prev=cur;
     }
     return prev[target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if((target+sum)%2==1 || abs(target)>sum) return 0;
        else return f(nums,abs((target+sum)/2));
    }
};