#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int solution(vector<int> stones, int k) {
    int min = 1, max = *max_element(stones.begin(),stones.end());
    
    while(min<=max){
        int mid = (min + max) / 2;
        int cnt = 0;
        for(int i=0;i<stones.size();i++){
            if(stones[i] - mid <= 0)
                cnt++;
            else
                cnt = 0;
            
            if(cnt >= k){
                break;
            }
        }
        
        if(cnt < k)
            min = mid + 1;
        else
            max = mid - 1;
    }
    
    return min;
}



int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    
    cout<<solution(stones, k)<<endl;
}
