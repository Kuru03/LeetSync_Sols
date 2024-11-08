class Solution
{
    public:
        vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
        {
            vector<int> vec = nums;
            vector<int> ans;
            int n = vec.size();
            for (int i = 1; i < n; i++)
            {
                vec[i] ^= vec[i - 1];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                int maxQueryVal = 0;
                for (int k = 0; k < maximumBit; k++)
                {
                   	// cout<<(1<<k)<<" "<<((1<<k) &vec[i])<<" "<<vec[i]<<endl;
                    if (((1 << k) &vec[i]) == 0)
                    {

                        maxQueryVal |= (1 << k);
                    }
                }
                ans.push_back(maxQueryVal);
            }
            return ans;
        }
};