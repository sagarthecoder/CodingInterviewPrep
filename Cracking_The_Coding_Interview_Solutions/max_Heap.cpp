#include <bits/stdc++.h>
#define ll long long
using namespace std;
void buildMaxHeap(int len, int index, int *ara)
{
    int left = index << 1;
    int right = left + 1;
    int correctIndex = -1;
    int maxValue = ara[index];
    if(left < len && ara[left] > maxValue) {
        maxValue = ara[left];
        correctIndex = left;
    }
    if(right < len && ara[right] > maxValue) {
        maxValue = ara[right];
        correctIndex = right;
    }
    if(correctIndex != -1) {
        swap(ara[index], ara[correctIndex]);
        buildMaxHeap(len, correctIndex, ara);
    }
}
int main()
{
    /*
    8
    10 20 25 6 12 15 4 16
    */
    int n;
    cin>>n;
    int ara[n];
    for(int i = 0 ; i < n ; i++) {
        cin>>ara[i];
    }
    for(int i = n/2; i >= 0 ; i--) {
        buildMaxHeap(n, i, ara);
    }
    for(int i = 0 ; i < n ; i ++) {
        cout<<"index "<<i<<" = "<<ara[i]<<endl;
    }
    return 0;

}
