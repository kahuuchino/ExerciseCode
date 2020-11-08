#include "stdio.h"
#include "stdlib.h"

int length(char *string)
{
    int i = 0, len = 0;
    for (i = 0; string[i] != '\0'; i++)
        ++len;
    return len;
}

void get_next(char *string, int *next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < length(string) - 1)
    {
        if(j == -1 || string[i]==string[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int kmp(char *mainstring, char *substring)
{
    int i = 0, j = 0;
    int *next;
    int length_main = length(mainstring);
    int length_sub = length(substring);
    next = (int *)malloc(sizeof(int) * length_sub);
    get_next(substring, next);
    while(i<=length_main&&j<=length_sub)
    {
        if(j==-1||mainstring[i]==substring[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
        if(j == length_sub)
            return i-j;
    }
    return -1;
}

int main(void)
{
    char a[] = "houhoiinkljnoihjokjljkhiouhiojo";
    char b[] = "hoi";
    int index;
    index = kmp(a, b);
    printf("%d", index);
    return 0;
}