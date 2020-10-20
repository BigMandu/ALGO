#include <stdio.h>
#define MAX 5
#define EMPTY -1
#define FULL MAX

int SP = EMPTY;
int stack[MAX];

int push(int data)
{
    if(SP>=FULL) return -1;
    SP++;
    stack[SP] = data;
    return 1;
}

int pop()
{
    if(SP==EMPTY) return -1;
    SP--;
    return 1;
}

void stprint()
{
    for(int i=EMPTY+1;i<=SP;i++){
        printf("stack[%d] : %d\n",i, *(stack)+i);
    }
}

int main()
{
    printf("SP -> %d\n",SP);
    for(int i=1;i<=MAX;i++){
        push(i);
        printf("----push, SP : %d----\n",SP);
        stprint();
    }
    printf("----pop----\n");
    pop();
    stprint();
    printf("SP -> %d\n",SP);
    return 0;
}