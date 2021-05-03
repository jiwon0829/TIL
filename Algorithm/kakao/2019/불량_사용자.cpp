#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int arr[10] = {0,};
    bool check[10] = {false,};
    
    sort(banned_id.begin(), banned_id.end());
    
    for(int i=0;i<banned_id.size();i++){
        if(i && banned_id[i] == banned_id[i-1]){
            continue;
        }
        for(int j=0;j<user_id.size();j++){
            
            if(!check[j] && banned_id[i].size() == user_id[j].size()){
                for(int k=0;k<banned_id[i].size();k++){
                    if(banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]){
                        break;
                    }
                    if(k == banned_id[i].size()-1){
                        check[j] = true;
                        arr[i]++;
                    }
                }
                
            }
        }
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return answer;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<string> usr_id1 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id1 = {"fr*d*", "abc1**"};   //2(2, 1)
    
    vector<string> usr_id2 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id2 = {"*rodo", "*rodo", "******"};  //2(2,
    
    vector<string> usr_id3 = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id3 = {"fr*d*", "*rodo", "******", "******"};  //3
    
    
    cout<<solution(usr_id1, banned_id1)<<endl;
    cout<<solution(usr_id2, banned_id2)<<endl;
    cout<<solution(usr_id3, banned_id3)<<endl;
}

