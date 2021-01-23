#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book.at(i+1).substr(0,phone_book.front().length()) == phone_book.at(i)){
            answer = false;
            break;
        }
    }
    return answer;
}
