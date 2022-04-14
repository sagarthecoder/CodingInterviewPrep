#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isLessCompressed(string &x)
{
    int len = x.size();
    if(len == 0) return false;
    int compressionLength = 0;
    int freqCount = 0;
    for(int i = 0; i < len ; i++) {
        if(i + 1 < len && x[i] == x[i + 1]) {
            freqCount += 1;
        }
        else {
            int lengthOfNumeric = log10(freqCount) + 1;
            compressionLength += (lengthOfNumeric + 1);
            freqCount = 1;
        }
    }
    return compressionLength < len;
}

string makeCompressed(string &x)
{
    if(!isLessCompressed(x)) {
        return x;
    }

    int len = x.size();
    int freqCount = 1;
    stringstream ss;
    for(int i = 0 ; i < len ; i++)
    {
        if(i + 1 < len && x[i] == x[i + 1]) {
            freqCount++;
        }
        else {
            ss << x[i] << freqCount;
            freqCount = 1;
        }
    }
    string compress = ss.str();
    return compress;

}
int main()
{
    // aabcccccaaa
    string x;
    cin>>x;
    cout<<"compressed String = "<<makeCompressed(x)<<endl;

}
