class Solution
{
    public:

        bool checkValid(vector<int> arr, int mid, int n)
        {
            int ans = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                ans += (arr[i] / mid);
                if (arr[i] % mid) ans++;
                if (ans > n) return false;
            }
            return true;
        }

    int minimizedMaximum(int n, vector<int> &arr)
    {
        int top = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            top = max(top, arr[i]);
        }
        int lo = 1, high = top, ans = 0;
        while (high >= lo)
        {
            int mid = (high + lo) / 2;
            bool check = checkValid(arr, mid, n);
           	// cout<<check<<" "<<mid<<endl;
            if (check)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};