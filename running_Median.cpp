#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int node;
    friend bool operator < (data a, data b)
    {
        return a.node > b.node;
    }
};

void makeValidHeap(priority_queue<int>&maxHeap, priority_queue<data>&minHeap)
{
    int minHeapSize = minHeap.size();
    int maxHeapSize = maxHeap.size();
    int diff = abs(maxHeapSize - minHeapSize);
    if(diff > 1) {
        while(diff > 1) {
            if(minHeapSize > maxHeapSize) {
                int topValue = minHeap.top().node;
                maxHeap.push(topValue);
                minHeap.pop();
            }
            else {
                int topValue = maxHeap.top();
                minHeap.push({topValue});
                maxHeap.pop();
            }
            diff -= 1;
        }
    }
}
int main()
{
    // n = total number
    int n;
    cin>>n;
    priority_queue<int>maxHeap;
    priority_queue<data>minHeap;
    double currentMedian = (double)INT_MAX;
    while(n--)
    {
        int x; // inserted value
        cin >> x;
        if(x < currentMedian) {
            maxHeap.push(x);
        }
        else {
            minHeap.push({x});
        }
        makeValidHeap(maxHeap, minHeap);
        if (maxHeap.size() == minHeap.size()) {
            currentMedian = (maxHeap.top() + minHeap.top().node) / 2.0;
        }
        else if(maxHeap.size() > minHeap.size()) {
            currentMedian = (double)maxHeap.top();
        }
        else {
            currentMedian = (double)minHeap.top().node;
        }
        cout<<"median = "<<setprecision(2)<< currentMedian << endl;
    }
    return 0;
}

