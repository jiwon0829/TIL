/* 월칸 코드 챌린지
//1번
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0;i<absolutes.size();i++){
        if(signs[i]){
            answer += absolutes[i];
        }
        else
            answer -= absolutes[i];
    }
    
    
    return answer;
}



//2번
#include <string>
#include <vector>
#include <stack>

using namespace std;

int Check(string s){
    stack<int> tmp;
    int ans = 0;
    //()12 []34 {}56
    for(int i=0;i<s.size();i++){
        if(tmp.empty()){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
                return 0;
        }
        
        if(s[i] == '('){
            tmp.push(1);
        }
        else if(s[i] == '['){
            tmp.push(3);
        }
        else if(s[i] == '{'){
            tmp.push(5);
        }
        else if(s[i] == ')' ){
            if(tmp.top() == 1){
                tmp.pop();
            }
            else{
                return 0;
            }
        }
        else if(s[i] == ']'){
            if(tmp.top() == 3){
                tmp.pop();
            }
            else{
                return 0;
            }
        }
        else if(s[i] == '}'){
            if(tmp.top() == 5){
                tmp.pop();
            }
            else{
                return 0;
            }
        }
    }
    if(!tmp.empty()){
        return 0;
    }
    return 1;
}

int solution(string s) {
    int answer = 0;

    for(int i=0;i<s.size();i++){
        string ans_s="";
        for(int j=i;j<s.size();j++){
            ans_s += s[j];
        }
        for(int j = 0;j<i;j++){
            ans_s += s[j];
        }
        answer += Check(ans_s);
    }
    
    return answer;
}


//3번
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    
    //애초에 0을 만들수 없는 경우
    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
    }
    if(sum)
        return -1;
    
    //가능한 경우
    vector<long long> A;
    for(int i=0;i<a.size();i++){
        A.push_back((long long)a[i]);
    }
    vector<int> cnt(a.size(), 0);
    vector<vector<int>> tree(a.size(), vector<int>());

    for (int i = 0; i < edges.size(); i++){
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
        
        //리프노드 판별을 위해
        cnt[edges[i][0]]++;
        cnt[edges[i][1]]++;
    }
    
    //리프노드면 부모노드와만 간선이 이루어졌음
    vector<int> LeafNode;
    for (int i = 0; i < a.size(); i++){
        if (cnt[i] == 1)
            LeafNode.push_back(i);
    }

    vector<int> check(a.size(), 0); //더했는지 판별
    queue<int> q;
    for (int i = 0; i < LeafNode.size(); i++)
        q.push(LeafNode[i]);
 
    while (q.empty() == false){
        int now = q.front();
        check[now] = 1;
        q.pop();
 
        for (int i = 0; i < tree[now].size(); i++){
            int next = tree[now][i];
            if (check[next])
                continue;
            A[next] += A[now];
            answer += abs(A[now]);
            A[now] = 0;
            cnt[next]--;
            if (cnt[next] == 1)
                q.push(next);
        }
    }
    
    for(int i=0;i<a.size();i++){
        if(A[i])
            return -1;
    }
    
    return answer;
}

*/


