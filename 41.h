#include"head.h"

class MedianFinder {
public:
    priority_queue<int,vector<int>, less<int>> pqMin;
    priority_queue<int,vector<int>, greater<int>> pqMax;
    int sMin, sMax;
    MedianFinder() {
    }
    
    void addNum(int num) {
        sMin = pqMin.size();
        sMax = pqMax.size();
        if(sMin == sMax)
        {
            pqMax.push(num);
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        else
        {
            pqMin.push(num);
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
    }
    
    double findMedian() {
        return (pqMin.size() + pqMax.size()) % 2 == 0 ? (pqMax.top() + pqMin.top()) / 2.0 : pqMin.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */