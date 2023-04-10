#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
vector<int> com[101];
bool visited[101];
int answer = 0;

void dfs(int num)
{
    ++answer;
    visited[num] = true;
    for(int i=0;i<com[num].size();i++)
        if (visited[com[num][i]] == false)
            dfs(com[num][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N>>M;
    int a, b;
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        sort(com[i].begin(), com[i].end());
    dfs(1);
    printf("%d\n", answer - 1);
}

