#include"head.h"
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return v(postorder, 0, int(postorder.size()) - 1);
    }
    bool v(vector<int> postorder, int begin, int end) {
        if(begin >= end) return true;
        int p = begin;
        while(postorder[p] < postorder[end]) p++;
        int m = p;
        while(postorder[p] > postorder[end]) p++;
        return p == end && v(postorder, begin, m - 1) && v(postorder, m, end - 1);
  }
};