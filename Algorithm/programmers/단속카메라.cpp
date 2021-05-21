#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;   //맨 처음 진입한 차량 카메라
    sort(routes.begin(), routes.end());  //진입이 순서로 정렬
    int range = routes[0][1];  //카메라가 찍힐 수 있는 마지막 거리 변수
    
    for(int i=1;i<routes.size();i++){
        //카메라 범위 뒤에 다른 차량의 진입
        if(range < routes[i][0]){
            answer++;  //카메라 한대 증가
            range = routes[i][1]; //카메라 거리 변경
        }
        //맨 앞 차보다 현재 차가 먼저 진출하는 경우
        if(range >= routes[i][1]){
            range = routes[i][1];
        }
    }
    return answer;
}
