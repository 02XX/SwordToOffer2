#include<iostream>
class Solution {
public:
    int fib(int n) {
        return f(n) % 1000000007;
    }
    int f(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        return f(n - 1) + f(n - 2);
    }
};

//动态规划最优
class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        vector<int> result(n + 1);
        result[0] = 0;
        result[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            result[i] = (result[i - 1] + result[i - 2]) % 1000000007;    
        }
        return result[n];
    }
};

//动态规划最优
class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int p = 0;
        int q = 1;
        int r = 0;
        for(int i = 2; i <= n; i++)
        {
            r = (p + q)% 1000000007;
            p = q;
            q = r;    
        }
        return r;
    }
};