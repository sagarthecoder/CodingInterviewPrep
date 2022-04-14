#include <bits/stdc++.h>
#define ll long long
using namespace std;
int checkNumberOfOddFreq(int checker)
{
    int odds = 0;
    while(checker)
    {
        if(checker % 2) {
            odds ++;
        }
        checker = checker >> 1;
    }
    return odds;
}
int main()
{
    //assume characters are lowercase
    string x;
    getline(cin,x);
    int checker = 0;
    for(char ch : x) {
        if(ch !=' ') {
            ch = tolower(ch);
            int serial = ch - 'a';
            checker ^= (1 << serial);
        }
    }
    int oddFreq = checkNumberOfOddFreq(checker);
    if(oddFreq > 1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }
    return 0;
}
