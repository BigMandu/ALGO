#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list * next;
}List;

List head; //첫번째 노드를 가리키고있는 Head

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
        printf("메모리 할당 실패\n");
        return -1; //할당 실패시 -1 return
    }
    *newnode = *data;
    
    if(head->next == NULL){ //첫 노드일 경우
        head->next = newnode;
        return 1;
    }
        pos = head->next;
        for(;;){ //head->next가 NULL이 나올때 까지 반복
            if(pos->next == NULL) break;
            pos = pos->next;
        } //pos->next가 NULL, 
        pos->next = newnode; //pos->next에 NULL이 아닌, newnode의 주소대입.
        return 1;
}

int delete_node(List * node)
{
    List * del;
    
    if(node->next == NULL){
            printf("삭제할 data없음\n");
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
        printf("출력할 node 없음\n");
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
    printf("입력할 data개수 : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_data(p);
        insert_node(&head,p);
        printf("----------%d번째 출력----------\n",i+1);
        print_list(&head);
    }

    printf("뒤에서부터 삭제할 node수 : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("----------%d번째 출력----------\n",i+1);
        delete_node(&head);
        print_list(&head);
    }
}