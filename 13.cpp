#include<queue>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m,n,k,0,0,visited);
    }
    int bfs(int m, int n, int k, vector<vector<bool>>& visited) {
        queue<pair<int,int>> s;
        int count = 1;
        s.push(make_pair(0,0));
        visited[0][0] = true;
        while(!s.empty())
        {
            int row = s.front().first;
            int column = s.front().second;
            s.pop();
            if(row + 1 >= 0 && row + 1 < m && !visited[row + 1][column] && get(row + 1) + get(column) <= k)
            {
                s.push(make_pair(row + 1, column));
                visited[row + 1][column] = true;
                count++;
            }
            if(column + 1 >= 0 && column + 1 < n && !visited[row][column + 1] &&  get(row) + get(column + 1) <= k)
            {
                s.push(make_pair(row, column + 1));
                visited[row][column + 1] = true;
                count++;
            }
        }
        return count;  
    }
    int dfs(int m, int n, int k, int row, int column ,vector<vector<bool>>& visited)
    {
        if(row < 0 || row >= m || column < 0 || column >= n || visited[row][column] ||get(row) + get(column) > k) return 0;
        visited[row][column] = true;
        return 1 + dfs(m,n,k,row+1,column,visited) + dfs(m,n,k,row,column+1,visited);
    }
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
};

int main()
{
    Solution A;
    cout << A.movingCount(1,2,1);
    return 0;
}