class trieNode
{
    public:
       	// vector<trieNode> child;
        unordered_map<string, trieNode*> child;
    bool end;
    trieNode()
    {
        end = 0;
    }
};

class trie
{
    public:
        trieNode *root = new trieNode();

    void insert(vector<string> s)
    {
        trieNode *temproot = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (temproot->child.count(s[i]) == 0)
            {
                trieNode *temp = new trieNode();
                temproot->child[s[i]] = temp;
            }
            temproot = temproot->child[s[i]];
        }
        temproot->end = 1;
        return;
    }
    bool include(vector<string> s)
    {
        trieNode *temproot = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (temproot->child.count(s[i]) == 0)
            {
                return true;
            }
            if (temproot->child[s[i]]->end == 1)
                return false;
            temproot = temproot->child[s[i]];
        }
        return true;
    }
};

class Solution
{
    public:
        static bool cmp(const string &a, const string &b)
        {
            return a.size() < b.size();
        }

    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> ans;
        sort(folder.begin(), folder.end(), cmp);
        trie root;

        for (int i = 0; i < folder.size(); i++)
        {
            vector<string> parse;
            string a;
            for (int j = 1; j < folder[i].size(); j++)
            {
                if (folder[i][j] == '/')
                {
                    parse.push_back(a);
                    a = "";
                    continue;
                }
                a += folder[i][j];
            }
            parse.push_back(a);
            bool add = root.include(parse);
            if (add)
            {
                root.insert(parse);
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};