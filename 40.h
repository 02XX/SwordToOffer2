#include"head.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};

//快排加数组划分
class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        Qsort(arr,0,int(arr.size()) - 1, k);
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
    void Qsort(vector<int>& arr, int i, int j, int k)
    {
        if(i >= j) return;
        int pivot = arr[i];
        int begin = i, end = j;
        while(begin < end)
        {
            while(begin < end && arr[end] >= pivot) end--;
            arr[begin] = arr[end];
            while(begin < end && arr[begin] <= pivot) begin++;
            arr[end] = arr[begin];
        }
        arr[begin] = pivot;
        if(begin == k) return;
        else if(k < begin)
            Qsort(arr, i, begin - 1,k);   
        else                                                                                                       
            Qsort(arr, begin + 1, j,k);
    }
};

class Solution3 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        Qsort(arr, 0, int(arr.size()) - 1);
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
    //快排
    void Qsort(vector<int>& arr, int i, int j)
    {
        if(i >= j) return;
        int pivot = arr[i];
        int begin = i, end = j;
        while(begin < end)
        {
            while(begin < end && arr[end] >= pivot) end--;
            arr[begin] = arr[end];
            while(begin < end && arr[begin] <= pivot) begin++;
            arr[end] = arr[begin];
        }
        arr[begin] = pivot;
        Qsort(arr, i, begin - 1);                                                                                                          
        Qsort(arr, begin + 1, j);
    }
};
