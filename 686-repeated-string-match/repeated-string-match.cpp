
class Solution {
public:
    vector<int> lps(string s) {
        int len = 0, i = 1;
        int n = s.size();
        vector<int> vec(n, 0);
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                vec[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = vec[len - 1];
                } else {
                    i++;
                }
            }
        }
        return vec;
    }

    bool stringMatcher(string pat, string s) {
        vector<int> vec = lps(pat);
        vector<int> ans;
        int i = 0, j = 0, n = s.size(), m = pat.size();
        while (i < n) {
            if (s[i] == pat[j]) {
                i++;
                j++;
                if (j == m) {
                    return 1;
                    ans.push_back(i - j);
                    j = vec[j - 1];
                }
            } else {
                if (j != 0)
                    j = vec[j - 1];
                else
                    i++;
            }
        }
        return 0;
        // return ans;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        string t = a;
        while (a.size() < m)
            a += t;
        int ans = 0;
        bool temp = stringMatcher(b, a);
        if (temp) return a.size() / t.size();
        int p = 2 * (a.size() / t.size());
        for (int i = 0; i <= p; i++) {
            a += t;
            temp = stringMatcher(b, a);
            if (temp) return a.size() / t.size();
        }
        return -1;
    }
};