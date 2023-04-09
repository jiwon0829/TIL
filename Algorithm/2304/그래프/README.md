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
최단경로 구조체 사용, 범위 체크 함수
```cpp
struct node {	int x, y, cnt;};
bool range(int x, int y) { return (x >= 0) && (x < M) && (y >= 0) && (y < N); }

void bfs(int x, int y)
{
	queue<node> q;
	chk[0][0] = 1;
	q.push({ x,y,0 });

	while (!q.empty())
	{
		node tmp;
		tmp = q.front();
		q.pop();
		if (tmp.x == M - 1 && tmp.y == N - 1)
			res = tmp.cnt;
		for (int i = 0; i < 4; i++)
		{
			node next;
			next.x = tmp.x + dirX[i];
			next.y = tmp.y + dirY[i];
			next.cnt = tmp.cnt + 1;
			if (range(next.x, next.y) && chk[next.y][next.x] == 0 && map[next.y][next.x] == 1)
			{
				chk[next.y][next.x] = 1;
				q.push(next);
			}
		}
	}
}
```
answer = res + 1
<br><br>
