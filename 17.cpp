class Solution {
public:
    vector<int> printNumbers(int n) {
        int fin = 0;
        for(int i = 0; i <n; i++)
        {
            fin = fin + pow(10,i)*9;
        }
        vector<int> r(fin);
        for(int i = 0; i < fin; i++)
        {
            r[i] = i + 1;
        }
        return r;
    }
};