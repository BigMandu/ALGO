/*
    �й�, �̸�, ������ �Է¹ް�
    �й���, ���������� ��� �����ϰ� Multiply Linked List�� �����ϰڽ��ϴ�.
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
    printf("�̸� : ");
    scanf("%s", d->name);
    printf("\n�й� : ");
    scanf("%d", &d->num);
    printf("\n���� : ");
    scanf("%lf", &d->score);

    d->next_num = NULL;
    d->next_score = NULL;
}

void insert_node(List *head, List *d)
{
    List *headtmp = head;
    List *newnode = (List *)calloc(1, sizeof(List));
    if (newnode == NULL){
        printf("�Ҵ� ����\n");
        return;
    }
    *newnode = *d;

    while (1){ //�й� �������� �߰�
        if (head->next_num == NULL || head->next_num->num > newnode->num){
            newnode->next_num = head->next_num;
            head->next_num = newnode;
            break;
        }

        if (head->next_num->num == newnode->num){
            printf("�ش� �й��� �̹� �ֽ��ϴ�.\n");
            return;
        }
        head = head->next_num;
    }
    head = headtmp; //����ص� head�ּ� ����

    while (1){ //���� �������� �߰�
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
            printf("������ �ڷ� ����\n");
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
        printf("�����data����\n");
        return;
    }
    head = head->next_num;
    for (;;)
    {
        if (head->next_num == NULL)
            return;
        printf("�й� : %3d, �̸� : %s, ���� : %2.lf\n", head->next_num->next_num, head->next_num->name, head->next_num->score);
        head = head->next_num;
    }
}


int main()
{
    List *d = (List *)malloc(sizeof(List));
    int input;
    do{
        printf("1. data�Է�\n");
        printf("2. �й��� ���\n");
        printf("3. ���� x ������ ���\n");
        printf("4. �й�����\n");
        printf("5. ����x��������\n");
        printf("0. ����\n");
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
            printf("������ �й� �Է� : ");
            scanf("%d",&input);
            delete_num(&Head,input);
            break;  
        case 5:
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("���Է�\n");
            break;
        }
    }while(input != 0);
    
    return 0;
}