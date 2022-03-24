#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int a = n / 3;
        int b = n % 3;
        int p = 1000000007;
        if(b == 0) return remainder(3, a ,p) % p;
        if(b == 1) return remainder(3, a-1, p) * 4 % 1000000007;
        return remainder(3, a, p) * 2 % p;
    }
    int remainder(int x,int a,int p)
    {
        int rem = 1;
        for(int i = 0; i < a; i++)
            rem = (rem * x) % p;
        return rem;
    }
       
};
int main()
{
    Solution A;
    cout << A.cuttingRope(1000);
    return 0;
}