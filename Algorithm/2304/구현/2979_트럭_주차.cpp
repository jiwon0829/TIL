#include <cstdio>
#include <cstring>

int main()
{
    int money[4], start, end;
    int cnt[101];
    int max_time=0, ans = 0;
    
    memset(cnt, 0, sizeof(cnt));
    scanf("%d %d %d",money+1, money+2, money+3);
    
    for(int i=0;i<3;i++){
        scanf("%d %d", &start, &end);
        if (max_time < end)
            max_time = end;
        for(int t=start;t<end;t++)
            ++cnt[t];
    }
    
    for(int i=1;i<=max_time;i++){
        if (cnt[i])
            ans += money[cnt[i]] * cnt[i];
    }
    printf("%d\n", ans);
}

