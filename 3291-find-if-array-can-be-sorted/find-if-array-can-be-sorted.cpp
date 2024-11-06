class Solution {
public:

    
    
    
    bool canSortArray(vector<int>& nums) {
         int i, j;
        int n=nums.size();
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-1; j++) {
                int t1=__builtin_popcount(nums[j+1]);
                int t2=__builtin_popcount(nums[j]);
                // cout<<nums[i]<<" "<<nums[j]<<" "<<t1<<" "<<t2<<endl; 
                if (nums[j] > nums[j + 1] && t1==t2) {
                    // cout<<nums[j]<<"    "<<nums[j+1]<<endl;
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for(int k=0;k<n-1;k++){
            // cout<<nums[k]<<" ";
            if(nums[k]>nums[k+1]) return false;
        }
        return true;
        
    }
};