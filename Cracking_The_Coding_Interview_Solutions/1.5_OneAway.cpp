#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isDeletedOrInserted(string s1, string s2)
{
    if(s1.size() < s2.size()) {
        swap(s1,s2);
    }
    int lengthS1 = s1.size();
    int lengthS2 = s2.size();
    int j = 0;
    for(int i = 0 ; i < lengthS1 ; i++) {
        if(s1[i] == s2[j]) {
            j++;
        }
    }
    return j == lengthS2;
}

bool isReplaced(string s1, string s2)
{
    int len = s1.size();
    int matchCount = 0;
    for(int i = 0 ; i < len ; i++) {
        if(s1[i] == s2[i]) {
            matchCount++;
        }
    }
    return matchCount >= len - 1;
}
bool isOneEdit(string s1, string s2)
{
    int lengthS1 = s1.size();
    int lengthS2 = s2.size();
    if(abs(lengthS1 - lengthS2) > 1) {
        return false;
    }
    else if(lengthS1 == lengthS2) {
        return isReplaced(s1,s2);
    }
    else {
        return isDeletedOrInserted(s1,s2);
    }

}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(isOneEdit(s1,s2)) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}
