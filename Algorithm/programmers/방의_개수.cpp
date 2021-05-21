#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

map <pair<int,int>, bool> visit;
map <pair<pair<int,int>,pair<int,int>>,bool> room_check;

int solution(vector<int> arrows) {
    int answer = 0;
    
    int x = 0, y = 0;
    visit.insert(make_pair(make_pair(x, y),true));
    
    for(int i=0;i<arrows.size();i++){
        for(int j=0;j<2;j++){
            int next_x = x + dx[arrows[i]];
            int next_y = y + dy[arrows[i]];
            
            if(visit[{next_x,next_y}] == true && room_check[{{x,y},{next_x,next_y}}] == false){
                answer++;
            }
            
            visit[{next_x,next_y}] = true;
            room_check[{{x,y},{next_x,next_y}}] = true;
            room_check[{{next_x,next_y},{x,y}}] = true;
            x = next_x;
            y = next_y;
        }
        
    }
    
    return answer;
}
