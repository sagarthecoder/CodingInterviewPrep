#include <bits/stdc++.h>
#define ll long long
using namespace std;
void buildMinHeap(int len, int index, int *ara)
{
    int left = index << 1;
    int right = left + 1;
    int correctIndex = -1;
    int minValue = ara[index];
    if(left < len && ara[left] < minValue) {
        minValue = ara[left];
        correctIndex = left;
    }
    if(right < len && ara[right] < minValue) {
        minValue = ara[right];
        correctIndex = right;
    }
    if(correctIndex != -1) {
        swap(ara[index], ara[correctIndex]);
        buildMinHeap(len, correctIndex, ara);
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
        buildMinHeap(n, i, ara);
    }
    for(int i = 0 ; i < n ; i ++) {
        cout<<"index "<<i<<" = "<<ara[i]<<endl;
    }
    return 0;

}
