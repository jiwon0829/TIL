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
최단경로 구하는 문제 => BFS
최단경로 구조체 사용, 범위 체크 함수 => answer = res + 1
```cpp
struct node {int x, y, cnt;};
bool range(int x, int y) { return (x >= 0) && (x < M) && (y >= 0) && (y < N); }

void bfs(int x, int y)
{
	queue<node> q;
	visited[0][0] = true;
	q.push({ x,y,0 });

	while (!q.empty())
	{
		node pos;
		pos = q.front();
		q.pop();
		if (pos.x == M - 1 && pos.y == N - 1)
			res = pos.cnt;
		for (int i = 0; i < 4; i++)
		{
			node next;
			next.x = pos.x + dx[i];
			next.y = pos.y + dy[i];
			next.cnt = pos.cnt + 1;
			if (range(next.x, next.y) && visited[next.y][next.x] == false && map[next.y][next.x] == 1)
			{
				visited[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}
```
<br><br>
