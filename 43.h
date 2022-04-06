#include"head.h"

class Solution {
public:
    int countDigitOne(int n) {
        string num = to_string(n);
        int s = num.size();
        int res = 0;
        for(int cur = 0; cur < s; cur++)
        {
            string pre = num.substr(0, cur);
            string last;
            if(cur + 1 < s)
                last = num.substr(cur + 1, s - cur - 1);
            else
                last = "";

            int preNum = 0, lastNum = 0;
            if(pre.size() > 0) preNum = stoi(pre);
            if(last.size() > 0) lastNum = stoi(last);

            int r1 = preNum * pow(10,last.size());
            int r2 = (num[cur] - '0' > 1 ? pow(10, last.size()) : lastNum + 1) * (num[cur] == '0' ? 0 : 1);
            res += r1 + r2;
        }
        return res;
    }
};