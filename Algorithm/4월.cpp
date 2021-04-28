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
#include <string>
#include <vector>
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
    
    sort(edges.begin(), edges.end());
    
    for(int i=0;i<edges.size();i++){
        if(a[edges[i][0]] && a[edges[i][1]]){
            a[edges[i][1]] += a[edges[i][0]];
            answer += a[edges[i][0]] > 0 ? a[edges[i][0]] : -a[edges[i][0]];
            a[edges[i][0]] = 0;
        }
        
        
    }
    for(int j=0;j<a.size();j++){
        if(a[j])
            return -1;
    }
    
    
    
    return answer;
}
*/


