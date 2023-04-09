#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool visited[1001];
vector<int> graph[1001];
int N, M, V;

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout<<v<<" ";
    
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for(auto i: graph[v])
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                cout <<i<<" ";
            }
        }
    }
}

void dfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    for(auto i : graph[v])
        if (visited[i] == false)
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int start, end;
    cin >> N >> M >> V;
    
    for(int i=0;i<M;i++)
    {
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i=1;i<=N;i++)
        sort(graph[i].begin(), graph[i].end());
    dfs(V);
    cout<<'\n';
    memset(visited, false, sizeof(visited));
    bfs(V);
}

