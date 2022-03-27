class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0)
        {
            int remainder = n % 2;
            if(remainder == 1) count++;
            n /= 2;
        }
        return count;
    }
};