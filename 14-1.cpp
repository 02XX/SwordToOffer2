#include<cmath>
#include<vector>
using namespace std;
//法一：本人解法 可以优化见法三
class Solution {
public:
    int cuttingRope(int n) {
        int max = 0;
        for(int i = 2; i <= n; i++)
        {
            int divisor = n / i;
            int remainder = n % i;
            int product = pow(divisor, (i - remainder)) * pow(divisor + 1, remainder);
            if(product > max) max = product;
        }
        return max;
    }
};

//法二：dp动态规划
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> product(n + 1, 0);
        product[0] = 0;
        product[1] = 1;
        product[2] = 1;
        for(int i = 3; i <= n ; i++)
        {
            for(int j = 2; j < i; j++)
            {
                product[i] = max(product[i],max(j*(i-j), j*product[i-j]));
            }

        }
        return product[n];
    }    
};


//法三
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int a = n / 3;
        int b = n % 3;
        if(b == 0) return pow(3, a);
        if(b == 1) return pow(3, a-1) * 4;
        return pow(3, a) * 2;
    }    
};
int main()
{
    
    return 0;
}