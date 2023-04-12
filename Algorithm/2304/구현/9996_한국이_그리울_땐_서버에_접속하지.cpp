#include <iostream>
#include <string>
using namespace std;

int main()
{ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    string patton;
    cin>>N;
    cin>>patton;
    string start = patton.substr(0, patton.find('*'));
    string end = patton.substr(patton.find('*') + 1);
    
    string filename;
    while (N--)
    {
        cin>>filename;
        if (patton.size() - 1 > filename.size())
            cout<<"NE\n";
        else if (filename.find(start) == 0)
        {
            filename = filename.substr(filename.size() - end.size());
            if (filename == end)
                cout<<"DA\n";
            else
                cout<<"NE\n";
        }
        else
            cout<<"NE\n";
        filename="";
    }
}

