#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right=12;   //* == 10, # == 12
    
    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7){
            answer+="L";
            left = num;
        }
        else if(num == 3 || num == 6 || num == 9){
            answer+="R";
            right = num;
        }
        else{
            if(num == 0)
                num = 11;
            
            int distance[2] = {0,};  //left, right
            distance[0] = abs(num - left);
            distance[1] = abs(num - right);
            
            distance[0] = distance[0] / 3 + distance[0] % 3;
            distance[1] = distance[1] / 3 + distance[1] % 3;
            
            if(distance[0] == distance[1]){
                if(hand == "left"){
                    answer+="L";
                    left = num;
                }
                else{
                    answer+="R";
                    right = num;
                }
            }
            else if(distance[0] > distance[1]){
                answer+="R";
                right = num;
            }
            else{
                answer+="L";
                left = num;
            }
        }
    }
    
    return answer;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> numbers1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand1 = "right";   //LRLLLRLLRRL
    vector<int> numbers2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand2 = "left";   //LRLLRRLLLRR
    vector<int> numbers3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string hand3 = "right";   //LLRLLRLLRL
    
    cout<<solution(numbers1, hand1)<<endl;
    cout<<solution(numbers2,hand2)<<endl;
    cout<<solution(numbers3, hand3)<<endl;
    
    
}

