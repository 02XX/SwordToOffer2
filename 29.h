
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        if(matrix.size() == 0) return r;
        int row = int(matrix.size());
        int column = int(matrix[0].size());
        int top = 0, low = row - 1;
        int left = 0, right = column - 1;
        while(true)
        {
            //向右
            for(int i = left; i <= right; i++)
            {
                r.push_back(matrix[top][i]);
            }
            if(++top > low) break;

            //向下
            for(int i = top; i <= low; i++)
            {
                r.push_back(matrix[i][right]);
            }
            if(--right < left) break;

            //向左
            for(int i = right; i >= left; i--)
            {
                r.push_back(matrix[low][i]);
            }
            if(--low < top) break;
            //向上
            for(int i = low; i >= top; i--)
            {
                r.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return r;
    }
};