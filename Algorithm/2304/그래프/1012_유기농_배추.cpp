#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,K;
int map[51][51];
bool visited[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool range(int x, int y){return ((x>=0) && (x<M)&&(y>=0)&&(y<N));}

void dfs(int y, int x)
{
    visited[y][x] = true;
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx = x+dx[i];
        ny = y+dy[i];
        if (range(nx,ny) && map[ny][nx] == 1 && visited[ny][nx] == false)
            dfs(ny,nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x, y,T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        cin >>M>>N>>K;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        for(int pos=0;pos<K;pos++)
        {
            cin>>x>>y;
            map[y][x] = 1;
        }
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if (map[i][j] == 1 && visited[i][j] == false)
                {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
}
