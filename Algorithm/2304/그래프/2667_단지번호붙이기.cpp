#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[26][26];
int map[26][26];
int dx[] = {0,0,-1,1};
int dy[] = {-1, 1, 0,0};
int N;
vector<int> label;


void dfs(int y, int x)
{
    int nx, ny;
    visited[y][x] = true;
    label[(int)label.size() - 1]++;
    for(int i=0;i<4;i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (x >= 0 && x <= N && y >= 0 && y <= N)
            if (map[ny][nx] == 1 && !visited[ny][nx])
                dfs(ny, nx);   
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    scanf("%d", &N);
    int i, j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%1d", &map[i][j]);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if (map[i][j] == 1 && !visited[i][j]){
                label.push_back(0);
                dfs(i, j);
            }
        }
    }
    sort(label.begin(), label.end());
    printf("%d\n",(int)label.size());
    for(int i=0;i<label.size();i++)
        printf("%d\n", label[i]);
}

