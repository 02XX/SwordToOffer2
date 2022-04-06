#include"head.h"

class Solution {
public:
    //摩尔投票法
    int majorityElement(vector<int>& nums) {
        int candidant, votes = 0;
        for(size_t i = 0; i < nums.size(); i++)
        {
            //票数为0，当前数即为候选人
            if(votes == 0)
            {
                candidant = nums[i];
                votes++;
            }
            //若候选人与当前遍历的数不一致，票数减一，否则票数加一
            else if(candidant != nums[i])
                votes--;
            else
                votes++;
        }
        return candidant;
    }
};