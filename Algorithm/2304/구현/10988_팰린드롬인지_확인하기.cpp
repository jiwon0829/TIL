#include <cstdio>
#include <cstring>

int main()
{
    char word[101];
    scanf("%s", word);
    for(int i=0;i<strlen(word)/2;i++){
        if (word[i] != word[strlen(word) - i - 1])
            return (printf("0\n"), 0);
    }
    return (printf("1\n"), 0);
}

