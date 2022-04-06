#include"head.h"

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if(str.size() == 1) return 1;
        vector<int> dp(str.size());
        dp[0] = 1;
        if(str.substr(0,2) <= "25" && str.substr(0,2) >= "10") dp[1] = 2;
        else dp[1] = 1;
        
        for(size_t i = 2; i < str.size(); i++)
        {
            if(str.substr(i - 1, 2) <= "25"&& str.substr(i - 1, 2) >= "10")
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp.back();
    }
};