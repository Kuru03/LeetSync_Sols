class Solution
{
    public:
        vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
        {
            vector<int> vec = nums;
            int n = vec.size();
            vector<int> ans(n,0);
            int curr=(1<<maximumBit)-1;
            for (int i = 0; i < n; i++)
            {
                if(i!=0)vec[i] ^= vec[i - 1];
                ans[n-i-1] = ~vec[i] & curr;
            }
            return ans;
        }
};