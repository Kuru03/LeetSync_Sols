class Solution {
public:
    bool wordPattern(string s, string pattern) {
        map<string, int> mpp;
        map<char, string> map;
        stringstream ss(pattern);
        string word;
        int t = 0;
        while (ss >> word) {
            cout << word << " " << t << endl;
            if (map.count(s[t]) == 0) {
                if(mpp[word]) return false;
                map[s[t]] = word;
                mpp[word]++;
            } else {
                if (map[s[t]] != word)
                    return false;
            }
            
            t++;
        }
        if(t!=s.size()) return false;
        return true;
    }
};