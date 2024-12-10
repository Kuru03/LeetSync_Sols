class Solution {
public:
    int maximumLength(string s) {
        vector<pair<int, int>> vec(26, {0, 0});
        unordered_map<string, int> mpp;
        int n = s.size();
        int prev = s[0];
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i != n && s[i] == prev) {
                cnt++;
            } else {
                if (vec[prev - 'a'].second < cnt) {
                    vec[prev - 'a'].first = vec[prev - 'a'].second;
                    vec[prev - 'a'].second = cnt;
                    // cout<<char(prev)<<" "<< vec[prev-'a'].first<<"
                    // "<<vec[prev-'a'].second<<endl;
                } else {
                    vec[prev - 'a'].first = max(vec[prev - 'a'].first, cnt);
                }
                char c = prev;
                // cout<<prev<<" "<<c<<endl;
                string t = "";
                t += c;
                t += to_string(cnt);
                // cout<<t<<endl;
                mpp[t]++;
                if (i == n)
                    break;
                prev = s[i];
                cnt = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char c = i + 'a';
            string t = "";
            t += c;
            t += to_string(vec[i].second);
            // cout << vec[i].first << " " << vec[i].second << " " << mpp[t]<< endl;
            if (mpp[t] >= 3)
                ans = max(vec[i].second, ans);
            else {
                ans = max(vec[i].second - 2, ans);
                if (vec[i].second != vec[i].first) ans = max(vec[i].first, ans);
                else ans = max(vec[i].first -1, ans);
                ans = max(ans, 0);
            }
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};