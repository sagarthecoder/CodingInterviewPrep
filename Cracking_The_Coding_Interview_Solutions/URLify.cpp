#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    getline(cin,x);
    int len = x.size();
    int validSpacesCount = 0;
    bool isSpaceCountable = false;
    int lastCharIndex = -1;
    for(int i = len - 1 ; i >= 0 ; i--) {
        if(!isSpaceCountable && x[i] !=' ') {
            isSpaceCountable = true;
            lastCharIndex = i;
        }
        if(isSpaceCountable && x[i] == ' ') {
            validSpacesCount += 1;
        }
    }
    if(lastCharIndex == -1) {
        cout<<x<<endl;
    }
    else {
        int i = lastCharIndex;
        int nextPosition = lastCharIndex + (validSpacesCount * 2);
        while(i >= 0) {
            if(x[i] != ' ') {
                x[nextPosition] = x[i];
                nextPosition -= 1;
            }
            else {
                x[nextPosition] = '0';
                x[nextPosition - 1] = '2';
                x[nextPosition - 2] = '%';
                nextPosition -= 3;
            }
            i--;
        }

        while(!x.empty() && x.back() == ' ') {
            x.pop_back();
        }

        cout<<"final = "<<x<<endl;
        cout<<"string size = "<<x.size()<<endl;
    }
}
