#include"head.h"

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int pre = nums[0];
        int maxSum = nums[0];
        for(size_t i = 1; i < nums.size(); i++)
        {
            pre = max(nums[i], pre + nums[i]);
            maxSum = max(pre, maxSum);
        }
        return maxSum;
    }
};

