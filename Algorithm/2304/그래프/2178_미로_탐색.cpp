#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool visited[101][101];
int map[101][101];
int len[101][101];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void bfs(int y, int x)
{
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    int nx,ny;
    
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny <= N){
                if (map[ny][nx] == 1 && visited[ny][nx] == false)
                {
                    visited[ny][nx] = true;
                    len[ny][nx] = len[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%1d",&map[i][j]);
    bfs(0,0);
    printf("%d\n", len[N-1][M-1] + 1);
}



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[101][101];
int map[101][101];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int len=10001;

void dfs(int y, int x, int depth)
{
    int nx,ny;
    if (x < 0 || x >= M || y < 0 || y >= N)
        return ;
    if (x == M -1 && y == N - 1){
        if (depth < len)
            len = depth;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (map[ny][nx] == 1 && visited[ny][nx] == false){
            visited[ny][nx] = true;
            dfs(ny, nx, depth + 1);
            visited[ny][nx] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%1d",&map[i][j]);
    dfs(0,0,1);
    printf("%d\n", len);
}

