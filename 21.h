class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> r(nums.size());
        int odd = 0;
        int even = int(nums.size()) - 1;
        for(int x : nums)
        {
            if(x % 2 != 0)
                r[odd++] = x;
            else
                r[even--] = x;
        }
        return r;
    }
};