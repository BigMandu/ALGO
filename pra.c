#include <stdio.h>
#include <stdlib.h>

int stringlen(char * str)
{   
    int ret = 0;
    while(str[ret]){
        ret++;
    }
    return ret;
}

void rmchar(char * str, int index, int len)
{
    if(index>len) index = len;
    for(int i=index;i<len;i++){
        str[i-1] = str[i];
    }
    str[len-1] = '\0';
    printf("%s",str);
}

int main()
{
    int length;
    char index;
    char * str = (char *)calloc(100,sizeof(char));
    gets(str);
    length = stringlen(str);

    for(int i=0;i<length;i++){
        scanf("%d",&index);
        rmchar(str, index, stringlen(str));
    }
}