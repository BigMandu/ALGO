/*
    학번, 이름, 학점을 입력받고
    학번순, 학점순으로 출력 가능하게 Multiply Linked List로 구현하겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int num;
    double score;
    char name[10];
    struct list *next_num;
    struct list *next_score;
} List;

List Head;

void create_data(List *d)
{
    printf("이름 : ");
    scanf("%s", d->name);
    printf("\n학번 : ");
    scanf("%d", &d->num);
    printf("\n학점 : ");
    scanf("%lf", &d->score);

    d->next_num = NULL;
    d->next_score = NULL;
}

void insert_node(List *head, List *d)
{
    List *headtmp = head;
    List *newnode = (List *)calloc(1, sizeof(List));
    if (newnode == NULL){
        printf("할당 실패\n");
        return;
    }
    *newnode = *d;

    while (1){ //학번 오름차순 추가
        if (head->next_num == NULL || head->next_num->num > newnode->num){
            newnode->next_num = head->next_num;
            head->next_num = newnode;
            break;
        }

        if (head->next_num->num == newnode->num){
            printf("해당 학번은 이미 있습니다.\n");
            return;
        }
        head = head->next_num;
    }
    head = headtmp; //백업해둔 head주소 대입

    while (1){ //점수 오름차순 추가
        if (head->next_score == NULL || head->next_score->score >= newnode->score){
            newnode->next_score = head->next_score;
            head->next_score = newnode;
            return;
        }
        head = head->next_score;
    }
}

void delete_num(List *head, int num)
{
    List *hdtmp = head;
    List *del;

    for (;;){
        if (head->next_num == NULL){
            printf("삭제할 자료 없음\n");
            return;
        }
        if (head->next_num->num == num){
            delete_score_node(hdtmp, head->next_num->score, num);
            del = head->next_num;
            head->next_num = head->next_num->next_num;
            free(del);
            return;
        }
    }
}
void delete_score_node(List *head, double score, int num)
{
    if (head->next_score == NULL)
        return;
    while (1){
        if (head->next_score->score == score && head->next_score->num == num){
            head->next_score = head->next_score->next_score;
            return;
        }
        head = head->next_score;
    }
}

/*
void delete_score(double score)
{
}
*/

void print_num_node(List *head)
{
    if (head->next_num == NULL)
    {
        printf("출력할data없음\n");
        return;
    }
    head = head->next_num;
    for (;;)
    {
        if (head->next_num == NULL)
            return;
        printf("학번 : %3d, 이름 : %s, 학점 : %2.lf\n", head->next_num->next_num, head->next_num->name, head->next_num->score);
        head = head->next_num;
    }
}


int main()
{
    List *d = (List *)malloc(sizeof(List));
    int input;
    do{
        printf("1. data입력\n");
        printf("2. 학번순 출력\n");
        printf("3. 구현 x 점수순 출력\n");
        printf("4. 학번삭제\n");
        printf("5. 구현x점수삭제\n");
        printf("0. 종료\n");
        printf(" >");
        scanf("%d", &input);
        switch (input){
        case 1: 
            create_data(d);
            insert_node(&Head,d);
            break;
        case 2: 
            print_num_node(&Head);
            break;
        case 3:
            break;
        case 4: 
            fflush(stdin);
            printf("삭제할 학번 입력 : ");
            scanf("%d",&input);
            delete_num(&Head,input);
            break;  
        case 5:
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("재입력\n");
            break;
        }
    }while(input != 0);
    
    return 0;
}