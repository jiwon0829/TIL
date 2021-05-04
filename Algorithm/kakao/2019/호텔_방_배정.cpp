#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> room;
long long find(long long n){
    if(room[n] == 0)
        return n;
    return room[n] = find(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i=0;i<room_number.size();i++){
        long long num = find(room_number[i]);
        answer.push_back(num);
        room[num] = num+1;
    }

    return answer;
}
