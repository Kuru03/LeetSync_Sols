class Solution {
public:
    map<string, int> map;
    int helper(string s, int ind, string t) {
        if (ind >= s.size())
            return (map[t]==0);
        int take = helper(s, ind + 1, t + s[ind]);
        int newTake = 0;
        if (t != "" && map[t] == 0) {
            map[t] = 1;
            string a = "";
            a += s[ind];
            newTake = 1 + helper(s, ind + 1, a);
            map[t] = 0;
        }
        return max(take, newTake);
    }
    int maxUniqueSplit(string s) { return helper(s, 0, ""); }
};
// class Solution {
// public:
//     unordered_set<string> seen;

//     int helper(string s, int ind) {
//         if (ind >= s.size()) return 0;

//         int maxSplits = 0;
//         string current = "";
//         for (int i = ind; i < s.size(); i++) {
//             current += s[i];
//             if (seen.find(current) == seen.end()) {
//                 seen.insert(current);
//                 maxSplits = max(maxSplits, 1 + helper(s, i + 1));
//                 seen.erase(current);
//             }
//         }

//         return maxSplits;
//     }

//     int maxUniqueSplit(string s) {
//         return helper(s, 0);
//     }
// };
