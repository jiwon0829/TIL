#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, c, start, end;
    int cnt[101];
    int max_time=0, ans = 0;
    
    memset(cnt, 0, sizeof(cnt));
    cin>>a>>b>>c;
    
    for(int i=0;i<3;i++){
        cin>>start>>end;
        if (max_time < end)
            max_time = end;
        for(int t=start;t<end;t++)
            ++cnt[t];
    }
    
    for(int i=1;i<=max_time;i++){
        if (cnt[i] == 3)
            ans += c * 3;
        else if (cnt[i] == 2)
            ans += b * 2;
        else if (cnt[i] == 1)
            ans += a;
    }
    cout<<ans<<'\n';
}

