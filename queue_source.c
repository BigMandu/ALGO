#include <stdio.h>

#define MAX 10
#define EMPTY 0
#define FULL MAX

int WP, RP;
int que[MAX];

int enq(int data)
{
    if(WP==FULL){
        return -1;
    }
    que[WP] = data;
    WP++;
    return 1;
}

int deq()
{
    if(WP==RP){
        return -1;
    }
    RP++;
    return 1;
}

void print_Que()
{
    for(int i=RP; i<WP;i++){
        printf("que[%d] : %d\n",i,que[i]);
    }
}

int main()
{
    printf("enq > 5\n");
    enq(5);
    printf("----print QUE----\n");
    print_Que();
    printf("enq > 10\n");
    enq(10);
    printf("----print QUE----\n");
    print_Que();
    printf("----deq\n");
    deq();
    printf("----print QUE----\n");
    print_Que();
    return 0;
}