#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int arr[320010];
vector<int> v[320010];
priority_queue<int> q;

int main() {
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		v[x].push_back(y);
        arr[y]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0)
			q.push(-i);
	}

	while (q.empty()==0) {
		int cur = -q.top();
        q.pop();
		cout<<cur<<" ";
		for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
			arr[next]--;
			if (arr[next] == 0)
				q.push(-next);
		}
	}
    cout<<endl;
}
