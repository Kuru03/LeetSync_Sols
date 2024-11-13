class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
                return b[1] > a[1];
            }
            return b[0] > a[0];
        }
    int findMaximumBeauty(vector<vector < int>> &arr, int query)
    {
        int lo = 0, hi = arr.size() - 1, ans = 0;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            if (arr[mid][0] > query)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
                ans = arr[mid][1];
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries)
    {
        sort(items.begin(), items.end(), cmp);
        for (int i = 1; i < items.size(); i++) items[i][1] = max(items[i][1], items[i - 1][1]);
        int n = queries.size();
        vector<int> maximumBeautyStore;
        for (int i = 0; i < n; i++)
        {
            int maximumQueryBeauty = findMaximumBeauty(items, queries[i]);
            maximumBeautyStore.emplace_back(maximumQueryBeauty);
        }
        return maximumBeautyStore;
    }
};