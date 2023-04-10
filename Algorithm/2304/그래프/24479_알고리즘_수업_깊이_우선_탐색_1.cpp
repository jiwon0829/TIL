#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
bool visited[100001];
vector<int> v[100001];
int answer[100001];
int cnt = 0;

void dfs(int num)
{
    if (visited[num] == true)
        return ;
    visited[num] = true;
    ++cnt;
    answer[num] = cnt;
    for(int i=0;i<v[num].size();i++)
        dfs(v[num][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int M, R, a, b;
    cin>>N>>M>>R;
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        sort(v[i].begin(), v[i].end());
    dfs(R);
    for(int i=1;i<=N;i++)
        printf("%d\n", answer[i]);
}

