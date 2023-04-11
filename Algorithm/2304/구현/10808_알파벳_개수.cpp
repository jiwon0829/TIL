#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string s;
    int answer[27];
    cin>>s;
    memset(answer, 0, sizeof(answer));
    for(int i=0;i<s.length();i++)
        answer[s[i] - 'a']++;
    for(int i=0;i<26;i++)
        printf("%d ", answer[i]);
}

