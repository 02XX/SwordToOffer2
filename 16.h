class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1) return x;
        long a = n;
        if(n < 0)
        {
            x = 1 / x;
            a = -a;
        }
        double r = 1;
        while(a > 0)
        {
            if(a % 2 == 1) r *= x;
            x *= x;
            a /= 2;
        }
        return r;
    }
};