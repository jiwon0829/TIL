#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int,int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> cnt;
    string tmp;
    bool check = false;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '{'){
            check = true;
            tmp.clear();
        }
        else if(s[i] == '}'){
            check = false;
            if(tmp.size()){
                int tmp_num = stoi(tmp);
                cnt[tmp_num]++;
                tmp.clear();
            }
        }
        else if(check && s[i] == ',' && tmp.size()){
            int tmp_num = stoi(tmp);
            cnt[tmp_num]++;
            tmp.clear();
        }
        else{
            tmp+=s[i];
        }
    }

    vector<pair<int, int>> v(cnt.begin(), cnt.end() );
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string s1 = "{{2},{2,1},{2,1,3},{2,1,3,4}}";   //[2, 1, 3, 4]
    string s2 = "{{1,2,3},{2,1},{1,2,4,3},{2}}";   //[2, 1, 3, 4]
    string s3 = "{{20,111},{111}}";   //[111, 20]
    string s4 = "{{123}}";   //[123]
    string s5 = "{{4,2,3},{3},{2,3,4,1},{2,3}}";   //[3, 2, 4, 1]
    
    
    vector<int> answer = solution(s1);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}

