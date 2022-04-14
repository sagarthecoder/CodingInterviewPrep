#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    /*
    4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    */
    int n;
    cin>>n;
    int ara[n][n];
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>ara[i][j];
        }
    }

    for(int i = 0 ; i < (n/2) ; i++) {
        int left = i;
        int right = n - 1 - i;
        int decreaseBy = 0;
        for(int j = left ; j < right ; j++) {
            int store1 = ara[i][j];
            int store2 = ara[j][right];
            int store3 = ara[right][right - decreaseBy];
            int store4 = ara[right - decreaseBy][i];
            ara[j][right] = store1;
            ara[right][right - decreaseBy] = store2;
            ara[right - decreaseBy][i] = store3;
            ara[i][j] = store4;
            decreaseBy++;
        }
    }
    cout<<"rotate by 90-> "<<endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
