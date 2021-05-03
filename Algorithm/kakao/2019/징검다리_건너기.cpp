#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    while(true){
        for(int i=0;i<stones.size();i++){
            if(stones[i])
                break;
            else if(i==stones.size()-1)
                return answer;
        }

        for(int i=0;;i++){
            if(i > stones.size()-1){
                answer++;
                break;
            }
            
            for(int j=0;j<k;j++){
                if(i+j > stones.size()-1){
                    break;
                }
                if(!stones[i+j]){
                    if(i+j == i+k-1)
                        return answer;
                    continue;
                }
                else{
                    stones[i+j]--;
                    i+=j;break;
                }
            }
        }
    }
    return answer;
}
