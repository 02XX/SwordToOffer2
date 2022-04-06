#include<vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 1) return numbers[0];
        int pre = 0, post = 1;
        while(post < int(numbers.size()) - 1)
        {
            if(numbers[post] < numbers[pre]) break;
            post++;
        }
        return min(numbers[post],numbers[pre]);
    }
};
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 0) return -1;
        int begin = 0;
        int end = int(numbers.size()) - 1;
        while(begin < end)
        {
            int mid = (begin + end) / 2;
            if(numbers[mid] > numbers[end]) begin = mid + 1;
            else if(numbers[mid] < numbers[end]) end = mid;
            else end--;
        }
        return numbers[begin];
        
    }
};  
