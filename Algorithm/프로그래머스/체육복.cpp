#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-(int)lost.size(); 
    
    for(int i =0; i<reserve.size();i++){
        for(int j =0;j<lost.size();j++){
            if(reserve[i] == lost[j]){ 
                answer++;
                reserve[i] = 0;
                lost[j] = 0;
                break;break;
            }
        }
    }
    
    for(int i =0;i<reserve.size();i++){
        if(answer == n)
            break;
        if(reserve[i] == 0)
            continue;
        for(int j =0;j<lost.size();j++){
            if(lost[j] == 0)
                continue;
            if((reserve[i] > 1 && reserve[i] - 1 == lost[j]) || (reserve[i] <= n && reserve[i]+1 == lost[j])){
                answer++;
                reserve[i] = 0;
                break;
            }
        }
    }
    return answer;
}
