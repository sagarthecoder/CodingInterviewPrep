
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // assum that x contains only lowercase characters.
    string x;
    cin>>x;
    bool isUnique = true;
    int checker = 0;
    for(char ch : x) {
        int val = ch - 'a';
        if((checker & (1 << val)) > 0) {
            isUnique = false;
            break;
        }
        checker |= (1 << val);
    }
    if(isUnique) {
        cout<<"Unique"<<endl;
    }
    else {
        cout<<"Not Unique"<<endl;
    }
    return 0;
}
