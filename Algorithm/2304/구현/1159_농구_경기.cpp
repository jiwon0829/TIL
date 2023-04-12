#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    int cnt[26]={0,};
    char name[31];
    bool predaja = false;
    for(int i=0;i<N;i++)
    {
        scanf("%s", name);
        cnt[name[0] - 'a']++;
        memset(name, 0, sizeof(name));
    }
    for(int i=0;i<26;i++){
        if (cnt[i] >= 5){
            printf("%c",'a'+i);
            predaja = true;
        }
    }
    if (predaja == false)
        printf("PREDAJA\n");
}

