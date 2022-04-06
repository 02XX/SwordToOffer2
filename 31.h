#include"head.h"
class Solution {
public:
    bool validateStackSequences(vector<int> pushed, vector<int> popped) {
        stack<int> s;
        int p = 0;
        for(int i = 0; i < pushed.size(); i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[p])
            {
                s.pop();
                p++;
            }
        }
        if(s.empty()) return true;
        return false;
    }
};