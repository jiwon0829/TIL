#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> point;
    int min_move = (int)name.size()-1;
    
    for(int i=0;i<name.size();i++){
        answer += name[i] - 'A' < 1 + 'Z' - name[i] ? name[i] - 'A' : 1 + 'Z' - name[i];
        
        int next = i+1;
        while(next < name.size() && name[next] == 'A')
            next++;
        min_move = min_move > i+name.size()-next+i ? i+name.size()-next+i : min_move;
    }

    return answer + min_move;
}
