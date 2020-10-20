#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list * next;
}List;

List head; //ù��° ��带 ����Ű���ִ� Head

void create_data(List * p)
{
    printf("insert data : ");
    scanf("%d",&p->data);
    p->next = NULL;
}

int insert_node(List * head, List * data)
{
    List * newnode;
    List * pos;
    newnode = (List *)malloc(sizeof(List));
    if(newnode == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return -1; //�Ҵ� ���н� -1 return
    }
    *newnode = *data;
    
    if(head->next == NULL){ //ù ����� ���
        head->next = newnode;
        return 1;
    }
        pos = head->next;
        for(;;){ //head->next�� NULL�� ���ö� ���� �ݺ�
            if(pos->next == NULL) break;
            pos = pos->next;
        } //pos->next�� NULL, 
        pos->next = newnode; //pos->next�� NULL�� �ƴ�, newnode�� �ּҴ���.
        return 1;
}

int delete_node(List * node)
{
    List * del;
    
    if(node->next == NULL){
            printf("������ data����\n");
            return -1;
    }
    del = node->next;
    for(;;){
        if(del->next == NULL){
            free(del);
            node->next = NULL;
            return 1;
        }
        node = del;
        del = del->next;
    }

}
void print_list(List * node)
{
    printf("Head->next : %8x\n",node->next);
    
    if(node->next == NULL) {
        printf("����� node ����\n");
        return;
    }
    node = node->next;

    while(1){
        printf("node addr: %8x, data: %d, node next: %8x\n",node,node->data,node->next);
        if(node->next == NULL) return;
        node = node->next;
    }
}

int main()
{
    int n;
    List * p = (List *)malloc(sizeof(List));
    printf("�Է��� data���� : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_data(p);
        insert_node(&head,p);
        printf("----------%d��° ���----------\n",i+1);
        print_list(&head);
    }

    printf("�ڿ������� ������ node�� : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("----------%d��° ���----------\n",i+1);
        delete_node(&head);
        print_list(&head);
    }
}