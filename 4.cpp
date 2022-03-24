#include<vector>
#include<iostream>
using namespace std;

//二分查找 时间复杂度O(nlogn)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = 0; int j = int(matrix.size()) - 1;
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if(!matrix[mid].empty())
            {
                if(matrix[mid][0] > target) j = mid - 1;
                if(matrix[mid][0] < target) i = mid + 1;
                if(matrix[mid][0] == target) return true;
            }
        }
        for(int k = j; k >= 0; k--)
        {
            int begin = 0;
            int end = int(matrix[0].size()) - 1;
            while(begin <= end)
            {
            int mid = (begin + end) / 2;
            if(matrix[k][mid] > target) end = mid - 1;
            if(matrix[k][mid] < target) begin = mid + 1;
            if(matrix[k][mid] == target) return true;
            }
        }
        return false;
    
    }
};


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = int(matrix.size()) - 1, j = 0;
        while(i >= 0 && j <= int(matrix[0].size()) - 1)
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;    
    }
};