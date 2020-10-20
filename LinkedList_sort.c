#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list * next;
}List;

List Head;

void create_data(List * d)
{
    int input;
    printf("data �Է� : ");
    scanf("%d",&input);
    d->data = input;
    d->next = NULL;
    return;
}

int insert_node(List * head, List * data)
{
    List * newnode;

    newnode = (List *)calloc(1, sizeof(List));
    if(newnode == NULL) {
        printf("�Ҵ� ����\n");
        return -1;
    }
    *newnode = *data;
    for(;;){
        if(head->next == NULL || head->next->data >= newnode->data){
            newnode->next = head->next;
            head->next = newnode;
            return 1;
        }
        head = head->next;
    }
}

int delete_node(List * head, int data)
{
    List * prev;

    for(;;){
        if(head->next == NULL) {
            printf("������ data ����\n");
            return -1;
        }
        if(head->next->data == data){
            prev = head->next;
            head->next = head->next->next;
            free(prev);
            return 1;
        }
        head = head->next;
    }
}

void print_list(List * head)
{
    printf("head : %8x, head->next : %8x\n",&head, head->next);
    if(head->next == NULL) {
        printf("����� Node ����\n"); return;
    }
    head = head->next;
    while(head != NULL){
        printf("node addr : %8x, node data : %8x, node next : %8x\n",head, head->data, head->next);
        head = head->next;
    }
}


int main()
{
    int n, data;
    List * d = (List *)malloc(sizeof(List));
    printf("�Է��� data ���� : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_data(d);
        printf("--------%d��° ���--------\n",i+1);
        insert_node(&Head,d);
        print_list(&Head);
    }
    
    printf("������ data���� �Է� : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("������ data �Է� : ");
        scanf("%d",&data);
        printf("--------%d��° ���--------\n",i+1);
        delete_node(&Head,data);
        print_list(&Head);
    }
    return 0;
}