#include<set>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> S;
        for(int i = 0; i < int(nums.size()); i++)
        {
            if(!S.empty() && S.count(nums[i])) return nums[i];
            else
                S.insert(nums[i]);
        }
        return -1;
    }   
};