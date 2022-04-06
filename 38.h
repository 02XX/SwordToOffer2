#include"head.h"

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        set<string> r = permutation2(s);
        for(string x : r)
        {
            res.push_back(x);
        }
        return res;
    }
    set<string> permutation2(string s) {
        if(s.size() == 1) return {s};
        set<string> res;
        for(size_t i = 0; i < s.size(); i++)
        {
            set<string> temp = permutation2(s.substr(0, i) + s.substr(i + 1, static_cast<int>(s.size()) - i));
            for(string x : temp)
            {
                res.insert(x + s[i]);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<string> rec;
    vector<int> vis;

    void backtrack(const string& s, int i, int n, string& perm) {
        if (i == n) {
            rec.push_back(perm);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
                continue;
            }
            vis[j] = true;
            perm.push_back(s[j]);
            backtrack(s, i + 1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);
        sort(s.begin(), s.end());
        string perm;
        backtrack(s, 0, n, perm);
        return rec;
    }
};
