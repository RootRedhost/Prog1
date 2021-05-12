#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void function(char* p, int x)
{
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main()
{
    printf("Hello World!\n");
    {
        char* h = "Hello";
        char* w = "World!";
        char* hw = (char*) malloc(strlen(h)+strlen(w)+2);
        strcpy(hw,h);
        hw[strlen(h)] = ' ';
        strcpy(hw+strlen(h)+1,w);
        printf("%s\n",hw);
    }
    function("foo",7);
    function("Kill",20);
    function("Assist",5);
}