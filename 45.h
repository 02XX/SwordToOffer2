#include"head.h"
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> res;
        for(int x : nums)
        {
            res.push_back(to_string(x));
        }
        sort(res.begin(), res.end(), [](string a, string b)
        {
            return a + b < b + a;
        });
        string r = "";
        for(string x : res)
        {
            r += x;
        }
        return r;
    }
};