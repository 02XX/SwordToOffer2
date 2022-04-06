#include"head.h"
class Solution {
public:
    int getKthNum(long k) {
        int i = 1;
        while(i * pow(10,i) < k)
        {
            k += pow(10,i);
            i++;
        }
        return (to_string(k / i)[k % i]) - '0';
    }
};
