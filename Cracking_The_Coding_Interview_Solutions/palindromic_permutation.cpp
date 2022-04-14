#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    getline(cin,x);
    int freqOfChar[128] = {0};
    for(char ch : x) {
        if(ch !=' ') {
            ch = tolower(ch);
            freqOfChar[(int)ch]++;
        }
    }
    int oddFreq = 0;
    for(int i = 0 ; i < 128 ; i++) {
        if(freqOfChar[i] % 2 != 0) {
            oddFreq ++;
        }
    }
    if(oddFreq > 1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
}
