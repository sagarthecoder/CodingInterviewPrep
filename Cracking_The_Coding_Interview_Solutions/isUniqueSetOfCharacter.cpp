
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // assum that x is a ascii String.
    string x;
    cin>>x;
    bool seen[128] = {0};
    bool isUnique = true;
    for(char ch : x) {
        int ascii = (int) ch;
        if(seen[ascii]) {
            isUnique = false;
            break;
        }
        seen[ascii] = true;
    }
    if(isUnique) {
        cout<<"Unique"<<endl;
    }
    else {
        cout<<"Not Unique"<<endl;
    }
    return 0;
}
