방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
=> 정렬되지않은 간선이 input
```cpp
for(int i=0;i<M;i++)
    {
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i=1;i<=N;i++)
        sort(graph[i].begin(), graph[i].end());
```
<br><br>
visited[] 빠른 초기화
```cpp
#include <cstring>
memset(visited, false, sizeof(visited));
```
<br><br>
